# New ports collection makefile for:    dvipsk + jpatch
# Date created:         25 Aug 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dvipsk
PORTVERSION=	5.95a
PORTREVISION=	0
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/TeX/ptex-win32/utils,:S,$,:udvipspatch,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,hrs/teTeX,:S,$,:udvipspatch,}
#		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:jpatch \
MASTER_SITE_SUBDIR=	systems/unix/teTeX/3.0/distrib/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTFILES=	${TETEX_SRC}${EXTRACT_SUFX} \
		dvipsk-${PORTVERSION}-p1.6a.tar.gz:udvipspatch
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	${TETEX_SRC}${EXTRACT_SUFX} \
		dvipsk-${PORTVERSION}-p1.6a.tar.gz

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
EXTRA_PATCHES=	${WRKDIR}/dvipsk-5.95a-p1.6a.diff
CONFIGURE_WRKSRC=${WRKDIR}/${TETEX_SRC}
BUILD_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk/dvipsk
INSTALL_WRKSRC=	${WRKDIR}/${TETEX_SRC}/texk/dvipsk

PLIST_SUB=	DVIPSDIR=${DVIPSDIR} \
		DVIPSCONFIGDIR=${DVIPSCONFIGDIR} \
		MKTEXLSR=${MKTEXLSR} \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		FONTSMAPDIR=${FONTSMAPDIR} \
		UPDMAP_SYS_PTEX=${UPDMAP_SYS_PTEX}
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
MLINKS=		dvips.1 odvips.1
INFO=		dvips

TETEX_SRC=	tetex-src-3.0

MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFCONFIGDIR=	share/texmf-config
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
FONTSMAPDIR=	${TEXMFDIR}/fonts/map/ptex
DVIPSDIR?=	${TEXMFDIR}/dvips/ptex
DVIPSCONFIGDIR?=${TEXMFCONFIGDIR}/dvips/ptex
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

UPDMAP_SYS_PTEX=${LOCALBASE}/bin/updmap-sys-ptex
TEXCONFIGBIN=	${LOCALBASE}/bin/texconfig-sys

post-configure:
	cd ${PATCH_WRKSRC} && \
		${RM} -rf udvipsk && ${CP} -R dvipsk udvipsk

do-build:
	cd ${WRKDIR}/${TETEX_SRC}/texk/dvipsk &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET}
	cd ${WRKDIR}/${TETEX_SRC}/texk/udvipsk &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} \
		program=udvips XDEFS=-DUDVIPS \
		${ALL_TARGET}

do-install:
	${MKDIR} ${PREFIX}/${DVIPSCONFIGDIR}/config
	cd ${WRKDIR}/${TETEX_SRC}/texk/dvipsk &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET}
	${INSTALL_PROGRAM} \
		${PATCH_WRKSRC}/udvipsk/udvips \
		${PREFIX}/bin
	${INSTALL_DATA} \
		${FILESDIR}/ptex-kanji.map \
		${PREFIX}/${FONTSMAPDIR}/dvips/kanji.map
	${MKTEXLSR}
	${SH} ${UPDMAP_SYS_PTEX} --enable Map=kanji.map

post-install:
	${TEXCONFIGBIN} dvips printcmd -
	${MKTEXLSR}

.include <bsd.port.mk>
