# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.5.9
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	A documentation system for C, C++ and other languages

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

USE_BISON=	build
USE_ICONV=	yes
ALL_TARGET=	all
USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL} --make ${GMAKE} \
		--install "${INSTALL}"
CONFIGURE_ENV=	CXX="${CXX}"

EXTRACT_AFTER_ARGS=|${TAR} -xpf - \
		--exclude '*/libmd5'	\
		--exclude '*/libpng'	\
		--exclude '*/tmake'

PLIST=		${WRKDIR}/plist
TMPDOCDEST=	${WRKDIR}/tmpdocdest

PLIST_FILES=	bin/doxygen \
		bin/doxytag

OPTIONS=	DOXYWIZARD "Enable doxywizard" on \
		LATEX "Enable LaTeX support" on

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS)
ALL_TARGET+=	docs
USE_PYTHON_BUILD=	yes
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz

.if !defined(WITHOUT_LATEX)
ALL_TARGET+=	pdf
BUILD_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX
USE_GHOSTSCRIPT_BUILD=	yes
MAKE_ARGS+=	HAVE_LATEX=yes
.endif # !defined(WITHOUT_LATEX)
.endif # !defined(NOPORTDOCS)

.if !defined(WITHOUT_DOXYWIZARD)
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui xml qmake_build moc_build rcc_build

# Need this in env for build
QTDIR?=		${QT_PREFIX}
CONFIGURE_ENV+=	QTDIR="${QTDIR}"
CONFIGURE_ARGS+=--with-doxywizard
.endif # !WITHOUT_DOXYWIZARD

.if ${MACHINE_ARCH:L} == alpha
CONFIGURE_ARGS+=	--enable-langs no
.endif

.ifndef WITHOUT_DOXYWIZARD
PLIST_FILES+=	bin/doxywizard
.endif

.include <bsd.port.pre.mk>

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
.ifndef NOPORTDOCS
	${MKDIR} ${TMPDOCDEST}/doxygen
	${RM} -f ${WRKSRC}/examples/diagrams/html/*.md5 \
		 ${WRKSRC}/examples/diagrams/html/*.map
	${TAR} -C ${WRKSRC} --exclude '*/_*' -cf - html \
		| ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' --exclude '*.dot' \
		-cf - examples \
	    | ${TAR} -C ${TMPDOCDEST}/doxygen --unlink -xf -
.ifndef WITHOUT_LATEX
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.dvi \
			${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/doxygen_manual.ps \
			${WRKSRC}/latex/archoverview.eps \
			${WRKSRC}/latex/doxygen_logo.eps \
			${TMPDOCDEST}/doxygen
.endif # WITHOUT_LATEX
	@cd ${TMPDOCDEST} \
	&& ${FIND} -s * -type f -o -type l \
		| ${SED} -e 's|^|share/doc/|'>> ${PLIST} \
	&& ${FIND} -d * -type d \
		| ${SED} -e 's|^|@dirrm share/doc/|' >> ${PLIST}
.endif # ! NOPORTDOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin/
.ifndef WITHOUT_DOXYWIZARD
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${PREFIX}/bin/
.endif
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/doxygen
	${TAR} -C ${TMPDOCDEST} -cf - doxygen \
		| ${TAR} -C ${PREFIX}/share/doc --unlink -xf -
.endif # ! NOPORTDOCS

.include <bsd.port.post.mk>
