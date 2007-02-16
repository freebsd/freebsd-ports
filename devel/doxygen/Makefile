# New ports collection makefile for:   doxygen
# Date created:        20 March 1998
# Whom:                Joep Grooten <joep@di.nl>
#
# $FreeBSD$
#

PORTNAME=	doxygen
PORTVERSION=	1.4.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	mwisnicki+freebsd@gmail.com
COMMENT=	A documentation system for C and C++

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

ALL_TARGET=	all

EXTRACT_AFTER_ARGS=|${TAR} -xpf - --exclude '*/libmd5'	\
	--exclude '*/libpng' --exclude '*/tmake'

CONFIGURE_ENV+=	CXX="${CXX}"
.if !defined(NOPORTDOCS)
ALL_TARGET+=	docs
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python # XXX: Replace with USE_PYTHON_BUILD
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz

.if !defined(WITHOUT_LATEX)
ALL_TARGET+=	pdf
PLIST_SUB+=	HAVE_LATEX=""
GSPORT?=	print/ghostscript-gnu
BUILD_DEPENDS+=	dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/${GHOSTSCRIPT_PORT}
MAKE_ARGS+=	HAVE_LATEX=yes
.else # !defined(WITHOUT_LATEX)
PLIST_SUB+=	HAVE_LATEX="@comment "
.endif # !defined(WITHOUT_LATEX)
.endif # !defined(NOPORTDOCS)

.if !defined(WITHOUT_DOXYWIZARD)
USE_QT_VER=	3
QT_INC=		${X11BASE}/include
QTNAME=		qt-mt
QT_OPENGL=
THREADLIBS=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}

# Need this in env for build
QTDIR?=		${QT_PREFIX}
CONFIGURE_ENV+=	QTDIR="${QTDIR}"
CONFIGURE_ARGS+=--with-doxywizard
PLIST_SUB+=	HAVE_DOXYWIZARD=""
.else # !WITHOUT_DOXYWIZARD
PLIST_SUB+=	HAVE_DOXYWIZARD="@comment "
.endif # !WITHOUT_DOXYWIZARD

USE_PERL5=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
QT_NONSTANDARD=	yes	# non-standard configure arguments
CONFIGURE_ARGS+=--prefix ${PREFIX} --perl ${PERL} --make ${GMAKE} \
		--install "${INSTALL}"

.if ${MACHINE_ARCH:L} == alpha
CONFIGURE_ARGS+=	--enable-langs no
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|TMAKE *=.*|TMAKE=${LOCALBASE}/bin/tmake|' \
		-e 's|TMAKEPATH *=.*|TMAKEPATH=${LOCALBASE}/share/tmake/freebsd-g++|' \
			${WRKSRC}/Makefile ${WRKSRC}/*/Makefile \
			${WRKSRC}/addon/doxywizard/Makefile

post-build:
	cd ${BUILD_WRKSRC}/examples; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxygen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxytag ${PREFIX}/bin
.ifndef WITHOUT_DOXYWIZARD
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doxywizard ${PREFIX}/bin
.endif
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/doxygen/html
	${RM} -f ${WRKSRC}/examples/diagrams/html/*.md5 \
		 ${WRKSRC}/examples/diagrams/html/*.map
	${TAR} -C ${WRKSRC} --exclude '*/_*' -cf - html \
		| ${TAR} -C ${PREFIX}/share/doc/doxygen --unlink -xf -
	${TAR} -C ${WRKSRC} --exclude '*/Makefile*' --exclude '*.dot' \
		-cf - examples \
	    | ${TAR} -C ${PREFIX}/share/doc/doxygen --unlink -xf -
.ifndef WITHOUT_LATEX
	${INSTALL_DATA} ${WRKSRC}/latex/doxygen_manual.dvi \
			${WRKSRC}/latex/doxygen_manual.pdf \
			${WRKSRC}/latex/doxygen_manual.ps \
			${WRKSRC}/latex/archoverview.eps \
			${WRKSRC}/latex/doxygen_logo.eps \
			${PREFIX}/share/doc/doxygen
.endif # WITHOUT_LATEXT
.endif # ! NOPORTDOCS

.include <bsd.port.mk>
