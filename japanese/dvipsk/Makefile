# New ports collection makefile for:    dvipsk + jpatch
# Date created:         25 Aug 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dvipsk
PORTVERSION=	5.94a
PORTREVISION=	0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/:jpatch \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,text/TeX/ptex-win32/utils,:S,$,:udvipspatch,}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTFILES=	tetex-src-${VER_TETEX}${EXTRACT_SUFX} \
		dvipsk-jpatch-p${VER_JPATCH}${EXTRACT_SUFX}:jpatch \
		udvips-5.94a-p1.6.patch:udvipspatch
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	tetex-src-${VER_TETEX}${EXTRACT_SUFX} \
		dvipsk-jpatch-p${VER_JPATCH}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A DVI to PostScript translator + Japanese patch

BUILD_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMF}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex
RUN_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMF}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

PATCH_WRKSRC=	${WRKDIR}/tetex-src-${VER_TETEX}/texk
EXTRA_PATCHES=	${WRKDIR}/dvipsk-5.92b-p${VER_JPATCH}.patch \
		${DISTDIR}/${DIST_SUBDIR}/udvips-5.94a-p1.6.patch
CONFIGURE_WRKSRC=${WRKDIR}/tetex-src-${VER_TETEX}
BUILD_WRKSRC=	${WRKDIR}/tetex-src-${VER_TETEX}/texk/dvipsk
INSTALL_WRKSRC=	${WRKDIR}/tetex-src-${VER_TETEX}/texk/dvipsk

PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-multiplatform \
		--without-texinfo --without-dialog \
		--with-system-ncurses --with-system-zlib \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-pnglib --with-pnglib-libdir=${LIBPNG_PREFIX}/lib \
		--with-pnglib-include=${LIBPNG_PREFIX}/include \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include
PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
CONFLICTS=	ja-ptex-base* dvips* ja-dvipsk-vflib-*

MAN1=		dvips.1 afm2tfm.1
INFO=		dvips

VER_TETEX=	2.0.2
VER_JPATCH=	1.6
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
TEXMF?=		share/texmf
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

TETEX_MODESW=	${PREFIX}/bin/tetex-modesw
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		MKTEXLSR=${MKTEXLSR}

post-configure:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}
	cd ${PATCH_WRKSRC} && ${RM} -rf udvipsk && ${CP} -R dvipsk udvipsk

do-build:
.for D in dvipsk odvipsk
	cd ${WRKDIR}/tetex-src-${VER_TETEX}/texk/${D} &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET}
.endfor
	cd ${WRKDIR}/tetex-src-${VER_TETEX}/texk/udvipsk &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} \
		program=udvips XDEFS=-DUDVIPS \
		${ALL_TARGET}

do-install:
.for D in dvipsk odvipsk
	cd ${WRKDIR}/tetex-src-${VER_TETEX}/texk/${D} &&\
		${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET}
.endfor
	${INSTALL_PROGRAM} \
		${PATCH_WRKSRC}/udvipsk/udvips \
		${PREFIX}/bin

post-install:
	${INSTALL_DATA} \
		${FILESDIR}/ptex-kanji.map \
		${PREFIX}/${TEXMF}/dvips/ptex/ptex-kanji.map
	${INSTALL_DATA} \
		${FILESDIR}/config.ps.ptex-tetex \
		${PREFIX}/${TEXMF}/dvips/config/config.ps.ptex-tetex
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
