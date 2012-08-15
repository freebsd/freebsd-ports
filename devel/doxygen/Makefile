# New ports collection makefile for:	doxygen
# Date created:		20 March 1998
# Whom:			Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.8.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	A documentation system for C, C++, and other languages

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BISON=	build
USE_ICONV=	yes
ALL_TARGET=	all
USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS=	--prefix ${PREFIX} --perl ${PERL} --make ${GMAKE} \
		--install "${INSTALL}"
MAKE_JOBS_UNSAFE=	yes
REINPLACE_ARGS=	-i ''

EXTRACT_AFTER_ARGS=|${TAR} -xpf - \
		--exclude '*/libmd5'	\
		--exclude '*/libpng'	\
		--exclude '*/tmake'

PLIST=		${WRKDIR}/plist
TMPDOCDEST=	${WRKDIR}/tmpdocdest

PLIST_FILES=	bin/doxygen

OPTIONS_DEFINE=	DOXYWIZARD LATEX
OPTIONS_DEFAULT=DOXYWIZARD LATEX
DOXYWIZARD_DESC=	Doxywizard support (requires QT4)

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS)
ALL_TARGET+=	docs
USE_PYTHON_BUILD=	yes
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz

.if ${PORT_OPTIONS:MLATEX}
ALL_TARGET+=	pdf
BUILD_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX
USE_GHOSTSCRIPT_BUILD=	yes
MAKE_ARGS+=	HAVE_LATEX=yes
.endif # LATEX
.endif # !defined(NOPORTDOCS)

.if ${PORT_OPTIONS:MDOXYWIZARD}
USE_QT4=	corelib gui xml qmake_build moc_build rcc_build

# Need this in env for build
QTDIR?=		${QT_PREFIX}
CONFIGURE_ENV=	QTDIR="${QTDIR}"
CONFIGURE_ARGS+=--with-doxywizard
.endif # DOXYWIZARD

.if ${MACHINE_ARCH:L} == alpha
CONFIGURE_ARGS+=	--enable-langs no
.endif

.if ${PORT_OPTIONS:MDOXYWIZARD}
PLIST_FILES+=	bin/doxywizard
.endif # DOXYWIZARD

pre-configure:
	@cd ${WRKSRC};for pro in src/*.pro.in addon/doxywizard/doxywizard.pro.in;do \
		${ECHO} "unix:LIBS += -liconv" >> $$pro; done
	@${CHMOD} +x ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|TMAKE *=.*|TMAKE=${LOCALBASE}/bin/tmake|' \
		-e 's|TMAKEPATH *=.*|TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++|' \
			${WRKSRC}/Makefile ${WRKSRC}/*/Makefile \
			${WRKSRC}/addon/doxywizard/Makefile

post-build:
	cd ${BUILD_WRKSRC}/examples; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} all

pre-install:
	${RM} -rf ${TMPDOCDEST} ${PLIST}
	${TOUCH} ${PLIST}
.if !defined(NOPORTDOCS)
	${MKDIR} ${TMPDOCDEST}/doxygen
	${RM} -f ${WRKSRC}/examples/diagrams/html/*.md5 \
		 ${WRKSRC}/examples/diagrams/html/*.map
	${TAR} -C ${WRKSRC} --exclude '*/_*' -cf - html \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' --exclude '*.dot' \
		-cf - examples \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
.if !defined(WITHOUT_LATEX)
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.dvi \
			${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/doxygen_manual.ps \
			${WRKSRC}/latex/archoverview.eps \
			${WRKSRC}/latex/doxygen_logo.eps \
			${TMPDOCDEST}/doxygen
.endif # !defined(WITHOUT_LATEX)
	@cd ${TMPDOCDEST} \
	&& ${FIND} -s * -type f -o -type l \
		| ${SED} -e 's|^|share/doc/|'>> ${PLIST} \
	&& ${FIND} -d * -type d \
		| ${SED} -e 's|^|@dirrm share/doc/|' >> ${PLIST}
.endif # !defined(NOPORTDOCS)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOXYWIZARD}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${PREFIX}/bin/
.endif # DOXYWIZARD
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/doxygen
	${TAR} -C ${TMPDOCDEST} -cf - doxygen \
		| ${TAR} -C ${PREFIX}/share/doc --unlink -xf -
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>
