# New ports collection makefile for:	ptex-tetex
# Date created:		9 Feb 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	ptex-tetex
PORTVERSION=	3.1.3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/:1
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib
PKGNAMEPREFIX=	ja-
DISTFILES=	ptex-src-${VER_PTEX}.tar.gz:1 ptex-texmf-2.1.tar.gz:1 \
		tetex-src-${VER_TETEX}.tar.gz
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	ASCII Japanese pTeX which supports teTeX distribution

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib
RUN_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USE_GMAKE=	yes
.if make(pre-build) || make(do-build)
MAKE_ENV=	TEXMFLOCAL=${WRKDIR}/texmf-tmp
.endif
ALL_TARGET=	default
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} TEXMFDIR=${TEXMFDIR}
CONFLICTS=	ja-ptex-base*
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
.if !make(do-patch)
WRKSRC=		${WRKDIR}/tetex-src-${VER_TETEX}/texk/web2c/ptex-${VER_PTEX}
.else
WRKSRC=		${WRKDIR}/tetex-src-${VER_TETEX}
.endif

WRKSRC_TETEX=	${WRKDIR}/tetex-src-${VER_TETEX}
WRKSRC_PTEX=	${WRKDIR}/ptex-src-${VER_PTEX}

VER_TETEX=	2.0.2
VER_PTEX=	${PORTVERSION}
KANJICODE?=	euc
TEXMFDIR?=	share/texmf
TEXMFCNF?=	${PREFIX}/${TEXMFDIR}/web2c/texmf.cnf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

INSTDIRS=	doc fonts jbibtex ptex
DOC_FILES=	COPYRIGHT COPYRIGHT.jis Changes.txt README.txt

post-extract:
	${MV} ${WRKSRC_PTEX} ${WRKSRC}

pre-configure:
	cd ${WRKSRC_TETEX} && \
		${SETENV} ${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} \
			--prefix=${PREFIX} \
			--disable-multiplatform \
			--without-texinfo --without-dialog \
			--with-system-ncurses --with-system-zlib \
			--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
			--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
			--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
			--with-pnglib-include=${LIBPNG_PREFIX}/include \
			--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
			--with-t1lib-include=${LIBT1_PREFIX}/include \
			--without-dvipsk --without-xdvik --without-oxdvik \
			--without-x11 --without-dvipdfm --without-omega \
			--without-pdftex --without-pdfetex && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}
	${SED} -e 's,%%TEXMFCNF%%,${TEXMFCNF},g' \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

pre-build:
	${MKDIR} ${WRKDIR}/texmf-tmp
	cd ${WRKDIR} && \
		${TAR} cf - ${INSTDIRS} | \
			(cd texmf-tmp && ${TAR} xf -) && \
		${SETENV} ${MAKE_ENV} ${MKTEXLSR} ${WRKDIR}/texmf-tmp

post-install:
	cd ${WRKDIR} && \
		${TAR} cf - ${INSTDIRS} | \
			(cd ${PREFIX}/${TEXMFDIR} && ${TAR} xf -) && \
		${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/${TEXMFDIR}/doc/ptex
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
