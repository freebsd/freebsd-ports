# Created by: Joep Grooten <joep@di.nl>
# $FreeBSD$

PORTNAME=	doxygen
PORTVERSION=	1.8.8
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Documentation system for C, C++, and other languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		bison gmake iconv perl5 python:2
ALL_TARGET=	all
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS=	--prefix ${PREFIX} --perl ${PERL} --make ${MAKE_CMD} \
		--install "${INSTALL}" --flex ${LOCALBASE}/bin/flex
REINPLACE_ARGS=	-i ''

EXTRACT_AFTER_ARGS=	--exclude '*/libmd5' \
			--exclude '*/libpng' \
			--exclude '*/tmake'

PLIST=		${WRKDIR}/plist
TMPDOCDEST=	${WRKDIR}/tmpdocdest

PLIST_FILES=	bin/doxygen

OPTIONS_DEFINE=	GRAPHVIZ LATEX QT4 HTMLDOCS PDFDOCS
OPTIONS_DEFAULT=	GRAPHVIZ LATEX
QT4_DESC=	Install Doxywizard GUI
HTMLDOCS_DESC=	Install documentation in HTML format
PDFDOCS_DESC=	Install documentation in PDF format

GRAPHVIZ_RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

LATEX_USE=	TEX=base,dvipsk,pdftex

QT4_USE=	QT4=corelib,gui,xml,qmake_build,moc_build,rcc_build
QT4_CONFIGURE_ENV=	QTDIR="${QTDIR}"
QT4_CONFIGURE_ON=	--with-doxywizard
QT4_PLIST_FILES=	bin/doxywizard

HTMLDOCS_ALL_TARGET=	docs
HTMLDOCS_BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

PDFDOCS_ALL_TARGET=	pdf
PDFDOCS_MAKE_ARGS=	HAVE_LATEX=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDFDOCS} && \
	(empty(PORT_OPTIONS:MHTMLDOCS) || empty(PORT_OPTIONS:MLATEX))
IGNORE=		PDFDOCS option requires HTMLDOCS and LATEX options to be set
.endif

.if ${PORT_OPTIONS:MPDFDOCS}
USE_GHOSTSCRIPT_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MQT4}
# Need this in env for the build
QTDIR?=		${QT_PREFIX}
.endif

pre-configure:
	@cd ${WRKSRC}; for pro in src/*.pro.in \
		addon/doxywizard/doxywizard.pro.in; do \
			${ECHO} "unix:LIBS += ${ICONV_LIB}" >> $$pro; done
	@${CHMOD} +x ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|TMAKE *=.*|TMAKE=${LOCALBASE}/bin/tmake|' \
		-e 's|TMAKEPATH *=.*|TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++|' \
			${WRKSRC}/Makefile ${WRKSRC}/*/Makefile \
			${WRKSRC}/addon/doxywizard/Makefile

post-build:
	${DO_MAKE_BUILD} -C ${BUILD_WRKSRC}/examples all

pre-install:
	${RM} -rf ${TMPDOCDEST} ${PLIST}
	${TOUCH} ${PLIST}
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${TMPDOCDEST}/doxygen
	${RM} -f ${WRKSRC}/examples/diagrams/html/*.md5 \
		 ${WRKSRC}/examples/diagrams/html/*.map
	${TAR} -C ${WRKSRC} --exclude '*/_*' -cf - html \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' --exclude '*.dot' \
		-cf - examples \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
.if ${PORT_OPTIONS:MPDFDOCS}
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/archoverview.eps \
			${TMPDOCDEST}/doxygen
.endif
	@cd ${TMPDOCDEST} \
	&& ${FIND} -s * -type f -o -type l \
		| ${SED} -e 's|^|share/doc/|' >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MQT4}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MHTMLDOCS}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/doxygen
	${TAR} -C ${TMPDOCDEST} -cf - doxygen \
		| ${TAR} -C ${STAGEDIR}${PREFIX}/share/doc --unlink -xf -
.endif

.include <bsd.port.mk>
