# Created by: hrs
# $FreeBSD$

PORTNAME=	ptex
PORTVERSION=	3.1.10
PORTREVISION=	6
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/:1 \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/:2
MASTER_SITE_SUBDIR=	obsolete/systems/unix/teTeX/3.0/distrib
PKGNAMESUFFIX=	-tetex
DISTFILES=	ptex-src-${VER_PTEX}${EXTRACT_SUFX}:1 \
		ptex-texmf-${VER_PTEXTEXMF}${EXTRACT_SUFX}:1 \
		${TETEX_SRC}${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX}:2 morisawa${EXTRACT_SUFX}:2
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	ASCII Japanese pTeX which supports teTeX distribution

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libwwwcore.so:${PORTSDIR}/www/libwww \
		libt1.so:${PORTSDIR}/devel/t1lib

CONFLICTS_INSTALL= \
		texlive-[0-9]* tex-web2c-[0-9]* \
		tex-kpathsea-[0-9]* tex-xdvik-[0-9]* \
		tex-dvipsk-[0-9]* tex-dvipdfmx-[0-9]*

USE_TEX=	base texmf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${KANJICODE}
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
USES=		gmake
.if make(do-build)
MAKE_ENV=	TEXMFLOCALDIR=${WRKDIR}/ptex-texmf \
		TEXMFDUMP=${LOCALBASE}/${TEXMFLOCALDIR} \
		TEXMFDISTDIR=${LOCALBASE}/${TEXMFDISTDIR}
.endif
MAKE_JOBS_UNSAFE=	yes
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

NO_STAGE=	yes
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
			--with-pnglib-include=${LIBPNG_PREFIX}/include/libpng15 \
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
