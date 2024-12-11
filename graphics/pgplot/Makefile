PORTNAME=	pgplot
PORTVERSION=	5.2.2
PORTREVISION=	30
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/
DISTNAME=	${PORTNAME}${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/FORTRAN library for drawing graphs on a variety of display devices
WWW=		https://sites.astro.caltech.edu/~tjp/pgplot/

LICENSE=	PGPLOT
LICENSE_NAME=	PGPLOT License
LICENSE_FILE=	${WRKSRC}/copyright.notice
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN_armv7=	link error: /usr/local/bin/ld: error: unsupported option: -z relro

LIB_DEPENDS=	libpng.so:graphics/png

USES=		fortran shebangfix xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xorgproto xt

MAKE_JOBS_UNSAFE=	yes

MAKE_ENV=	SSP_CFLAGS=
SHEBANG_FILES=	makehtml maketex
FFLAGS+=	-std=legacy
SUFFIXES=	flib clib bin
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH:M*64*}
EXTRA_PATCHES +=	${FILESDIR}/drivers_64bit_patch
.endif

PORTDATA=	grfont.dat

.if ${PORT_OPTIONS:MDOCS}
DOCS=	cpg/cpgplot.doc pgplot-routines.tex pgplot.doc pgplot.html \
	readme.pgdisp rgb.txt
SUFFIXES+=	doc
PORTDOCS=	${DOCS:C|.*/||}
USES+=		perl5
USE_PERL5=	build
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLES=	Makefile.demo cpg/cpgdemo.c examples/pgdemo*.f
PORTEXAMPLES=	${EXAMPLES:C|.*/||}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|png_ptr->jmpbuf|png_jmpbuf(png_ptr)|' \
		${WRKSRC}/drivers/pndriv.c
	@${REINPLACE_CMD} -e 's|/usr/local/pgplot|${DATADIR}|g' \
		${WRKSRC}/src/grgfil.f
	@cd ${FILESDIR}; ${CP} Makefile* drivers.list grexec.f ${WRKSRC}
	@${CP} ${WRKSRC}/src/*.inc ${WRKSRC}

do-build:
.for s in ${SUFFIXES}
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	Makefile.${s} ${_MAKE_JOBS} ${MAKE_ARGS}
.endfor

do-install:
	@cd ${WRKSRC}; \
	${INSTALL_PROGRAM} pgxwin_server pgdisp ${STAGEDIR}${PREFIX}/bin; \
	${INSTALL_DATA} *.a ${STAGEDIR}${PREFIX}/lib; \
	${INSTALL_LIB} *.so.5* ${STAGEDIR}${PREFIX}/lib; \
	${INSTALL_DATA} cpgplot.h ${STAGEDIR}${PREFIX}/include
.for f in libcpgplot.so libpgplot.so
	@${LN} -sf ${f}.5 ${STAGEDIR}${PREFIX}/lib/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDATA} ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}; ${CP} pgdispd/aaaread.me readme.pgdisp; \
	${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.if defined(MAINTAINER_MODE) && !defined(BATCH)
DEMO?=	cpgdemo

check test: build
	@cd ${WRKSRC}; ${CP} cpg/cpgdemo.c examples/pgdemo*.f ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
	Makefile.demo ${_MAKE_JOBS} ${MAKE_ARGS}
	@${SETENV} LD_LIBRARY_PATH="${LOCALBASE}/lib:${WRKSRC}" \
	PGPLOT_DIR="${WRKSRC}" PGPLOT_DEV="/xwin" ${WRKSRC}/${DEMO}
.endif

.include <bsd.port.mk>
