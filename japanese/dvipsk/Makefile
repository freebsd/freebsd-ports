# New ports collection makefile for:    dvipsk + jpatch
# Date created:         25 Aug 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dvipsk
PORTVERSION=	5.94a
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.dante.de/tex-archive/systems/unix/teTeX-beta/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:jpatch \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/TeX/ptex-win32/utils,:S,$,:udvipspatch,}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTFILES=	${TETEX_SRC}${EXTRACT_SUFX} \
		dvipsk-jpatch-p${VER_JPATCH}${EXTRACT_SUFX}:jpatch \
		udvips-5.94a-p1.6a1.patch:udvipspatch
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	${TETEX_SRC}${EXTRACT_SUFX} \
		dvipsk-jpatch-p${VER_JPATCH}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A DVI to PostScript translator + Japanese patch

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFDIR}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFDIR}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

PATCH_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk
EXTRA_PATCHES=	${WRKDIR}/dvipsk-5.92b-p${VER_JPATCH}.patch \
		${DISTDIR}/${DIST_SUBDIR}/udvips-5.94a-p1.6a1.patch
CONFIGURE_WRKSRC=${WRKDIR}/${TETEX_SRC}
BUILD_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk/dvipsk
INSTALL_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk/dvipsk

PLIST_SUB=	DVIPSDIR=${DVIPSDIR} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMFDIR=${TEXMFDIR} \
		FONTSMAPDIR=${FONTSMAPDIR}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-multiplatform \
		--without-texinfo \
		--without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--without-xdvik --without-oxdvik
CONFLICTS=	ja-ptex-base-[0-9]* \
		dvipsk-tetex-[0-9]* \
		dvips-[0-9]*

MAN1=		dvips.1 afm2tfm.1
INFO=		dvips

TETEX_SRC=	tetex-src-2.0.2
VER_JPATCH=	1.6a1

MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
FONTSMAPDIR=	${TEXMFDIR}/fonts/map/dvips
DVIPSDIR?=	${TEXMFDIR}/dvips/ptex
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

UPDMAP_SUB=	PREFIX=${PREFIX} \
		TEXMFDIR=${TEXMFDIR} \
		DVIPSDIR=${DVIPSDIR}

post-configure:
	cd ${PATCH_WRKSRC} && \
		${RM} -rf udvipsk && ${CP} -R dvipsk udvipsk

do-build:
.for D in dvipsk odvipsk
	cd ${WRKDIR}/${TETEX_SRC}/texk/${D} &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET}
.endfor
	cd ${WRKDIR}/${TETEX_SRC}/texk/udvipsk &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} \
		program=udvips XDEFS=-DUDVIPS \
		${ALL_TARGET}

do-install:
	${MKDIR} ${PREFIX}/${DVIPSDIR}/config
.for D in dvipsk odvipsk
	cd ${WRKDIR}/${TETEX_SRC}/texk/${D} &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET}
.endfor
	${INSTALL_PROGRAM} \
		${PATCH_WRKSRC}/udvipsk/udvips \
		${PREFIX}/bin
	${MKDIR} ${PREFIX}/${FONTSMAPDIR}/ptex
	${INSTALL_DATA} \
		${FILESDIR}/ptex-kanji.map \
		${PREFIX}/${FONTSMAPDIR}/ptex/kanji.map
	(${CAT} ${LOCALBASE}/${TEXMFDISTDIR}/web2c/updmap.cfg; \
	 ${ECHO_CMD} "Map kanji.map" ) > ${WRKDIR}/updmap.cfg
	${INSTALL_DATA} \
		${WRKDIR}/updmap.cfg \
		${PREFIX}/${TEXMFDIR}/web2c/ptex/updmap.cfg
	${SED} ${UPDMAP_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/updmap-ptex.in > ${WRKDIR}/updmap-ptex
	${INSTALL_SCRIPT} ${WRKDIR}/updmap-ptex ${PREFIX}/bin/updmap-sys-ptex
	${MKTEXLSR}
	${SH} ${PREFIX}/bin/updmap-sys-ptex --nohash

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
