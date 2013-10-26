# Created by: jmz
# $FreeBSD$

PORTNAME=	pgplot
PORTVERSION=	5.2.2
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/
DISTNAME=	${PORTNAME}${PORTVERSION:R}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	C/FORTRAN library for drawing graphs on a variety of display devices

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

MAKE_JOBS_UNSAFE=	yes

USES=		shebangfix
USE_FORTRAN=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11 xproto xt

MAKE_ENV=	SSP_CFLAGS=
SHEBANG_FILES=	makehtml maketex
SUFFIXES=	flib clib bin
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH:M*64*}
EXTRA_PATCHES +=	${FILESDIR}/drivers_64bit_patch
.endif

.ifndef(NOPORTDATA)
PORTDATA=	grfont.dat
.endif

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
	${INSTALL_PROGRAM} pgxwin_server pgdisp ${PREFIX}/bin; \
	${INSTALL_LIB} *.a *.so.5* ${PREFIX}/lib; \
	${INSTALL_DATA} cpgplot.h ${PREFIX}/include
.for f in libcpgplot.so libpgplot.so
	@${LN} -sf ${f}.5 ${PREFIX}/lib/${f}
.endfor
.ifndef(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDATA} ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}; ${CP} pgdispd/aaaread.me readme.pgdisp; \
	${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}; ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
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
