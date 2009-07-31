# New ports collection makefile for:	ptex
# Date created:		9 Feb 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	ptex
PORTVERSION=	3.1.10
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/:1 \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/:2
MASTER_SITE_SUBDIR=	obsolete/systems/unix/teTeX/3.0/distrib
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTFILES=	ptex-src-${VER_PTEX}${EXTRACT_SUFX}:1 \
		ptex-texmf-${VER_PTEXTEXMF}${EXTRACT_SUFX}:1 \
		${TETEX_SRC}${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX}:2 morisawa${EXTRACT_SUFX}:2
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	ASCII Japanese pTeX which supports teTeX distribution

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USE_GMAKE=	yes
.if make(do-build)
MAKE_ENV=	TEXMFLOCALDIR=${WRKDIR}/ptex-texmf \
		TEXMFDUMP=${LOCALBASE}/${TEXMFLOCALDIR} \
		TEXMFDISTDIR=${LOCALBASE}/${TEXMFDISTDIR}
.endif
ALL_TARGET=	default
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		TEXMFDISTDIR=${TEXMFDISTDIR} \
		TEXMFCONFIGDIR=${TEXMFCONFIGDIR} \
		TEXMFVARDIR=${TEXMFVARDIR} \
		TEXMFDIR=${TEXMFDIR} \
		UPDMAP_SYS="${UPDMAP_SYS}" \
		UPDMAPDIR=${UPDMAPDIR}

PATCH_WRKSRC=	${WRKDIR}/${TETEX_SRC}
WRKSRC=		${WRKDIR}/${TETEX_SRC}/texk/web2c/ptex

TETEX_SRC=	tetex-src-3.0
VER_PTEX=	${PORTVERSION}
VER_PTEXTEXMF=	2.5
KANJICODE?=	euc
TEXMFDIR?=	share/texmf
TEXMFDISTDIR?=	share/texmf-dist
TEXMFCONFIGDIR?=share/texmf-config
TEXMFLOCALDIR?=	share/texmf-local
TEXMFVARDIR?=	share/texmf-var
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}
FONTSMAPDIR=	${TEXMFDIR}/fonts/map/ptex
FONTSMAPVARDIR=	${TEXMFVARDIR}/fonts/map/ptex

UPDMAP_SYS=	${PREFIX}/bin/updmap-sys --progname=ptex
UPDMAPDIR=	${TEXMFDIR}/updmap

SUB_FILES=	updmap-ptex
SUB_LIST=	PREFIX=${PREFIX} \
		TEXMFDIR=${TEXMFDIR} \
		DVIPSDIR=${DVIPSDIR} \
		TEXMFVARDIR=${TEXMFVARDIR} \
		FONTSMAPDIR=${FONTSMAPDIR} \
		FONTSMAPVARDIR=${FONTSMAPVARDIR} \
		UPDMAPDIR=${UPDMAPDIR}

DOC_FILES=	COPYRIGHT COPYRIGHT.jis Changes.txt README.txt

post-extract:
	${MV} ${WRKDIR}/ptex-src-${VER_PTEX} ${WRKSRC}
	${MKDIR} ${WRKDIR}/ptex-texmf/fonts/map/ptex/dvips \
		${WRKDIR}/ptex-texmf/fonts/tfm/ptex/dvips \
		${WRKDIR}/ptex-texmf/fonts/vf/ptex
	${MV} ${WRKDIR}/jis/tfm/ptex/* \
		${WRKDIR}/morisawa/tfm/ptex/* \
		${WRKDIR}/ptex-texmf/fonts/tfm/ptex/
	${MV} ${WRKDIR}/jis/tfm/dvips/* \
		${WRKDIR}/morisawa/tfm/dvips/* \
		${WRKDIR}/ptex-texmf/fonts/tfm/ptex/dvips/
	${MV} ${WRKDIR}/jis/vf/* \
		${WRKDIR}/morisawa/vf/* \
		${WRKDIR}/ptex-texmf/fonts/vf/ptex/
	${MV} ${WRKDIR}/jis/jis.map \
		${WRKDIR}/morisawa/morisawa.map \
		${WRKDIR}/ptex-texmf/fonts/map/ptex/dvips/
	cd ${WRKDIR} && \
		${RM} -f ptex-texmf/ptex/platex/base/.cvsignore && \
		${FIND} ptex-texmf -type d | ${XARGS} ${CHMOD} 755 && \
		${FIND} ptex-texmf -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

pre-configure:
	${SETENV} ${MAKE_ENV} ${MKTEXLSR} ${WRKDIR}/ptex-texmf
	cd ${WRKDIR}/${TETEX_SRC} && \
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
			--without-xdvik --without-oxdvik \
			--without-dvipsk --without-odvipsk \
			--without-x11 --without-dvipdfm && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

post-install:
	cd ${WRKDIR}/ptex-texmf && \
		${TAR} cf - --exclude="*.orig" doc fonts jbibtex ptex | \
			(cd ${PREFIX}/${TEXMFDIR} && ${TAR} xopf -) && \
		${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/${TEXMFDIR}/doc/ptex
	${MKDIR} ${PREFIX}/${TEXMFCONFIGDIR}/texconfig/ptex \
		 ${PREFIX}/${TEXMFCONFIGDIR}/web2c/ptex \
		 ${PREFIX}/${TEXMFCONFIGDIR}/dvips/ptex
	${INSTALL_DATA} ${FILESDIR}/tcfmgr.map \
		${PREFIX}/${TEXMFCONFIGDIR}/texconfig/ptex/tcfmgr.map
	${INSTALL_DATA} ${LOCALBASE}/${TEXMFDISTDIR}/web2c/updmap.cfg \
		${PREFIX}/${TEXMFDIR}/web2c/ptex/updmap.cfg
	${INSTALL_DATA} ${LOCALBASE}/${TEXMFDISTDIR}/web2c/updmap.cfg \
		${PREFIX}/${TEXMFCONFIGDIR}/web2c/ptex/updmap.cfg
	${MKDIR} ${PREFIX}/${FONTSMAPDIR}/dvips/updmap \
		${PREFIX}/${FONTSMAPVARDIR}/dvips/updmap \
		${PREFIX}/${FONTSMAPDIR}/dvipdfm/updmap \
		${PREFIX}/${FONTSMAPVARDIR}/dvipdfm/updmap \
		${PREFIX}/${FONTSMAPDIR}/pdftex/updmap \
		${PREFIX}/${FONTSMAPVARDIR}/pdftex/updmap
	${INSTALL_SCRIPT} ${WRKDIR}/updmap-ptex ${PREFIX}/${UPDMAPDIR}/updmap.ptex
	${MKTEXLSR}
	if ${LOCALBASE}/bin/kpsewhich -format=map psfonts_jp.map > /dev/null 2>&1; then \
		${SH} ${UPDMAP_SYS} --enable Map=psfonts_jp.map; \
	else \
		${SH} ${UPDMAP_SYS}; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
