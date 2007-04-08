# New ports collection makefile for:	ptex
# Date created:		9 Feb 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	ptex
PORTVERSION=	3.1.9
PORTREVISION=	5
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/:1 \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/:2
MASTER_SITE_SUBDIR=	systems/unix/teTeX/3.0/distrib
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
.if make(post-extract) || make(do-build)
MAKE_ENV=	TEXMFLOCALDIR=${WRKDIR}/texmf-tmp \
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
		UPDMAPDIR=${UPDMAPDIR} \
		MAPDIR=${MAPDIR} \
		VFDIR=${VFDIR} \
		TFMDIR=${TFMDIR}

.if !make(do-patch)
WRKSRC=		${WRKDIR}/${TETEX_SRC}/texk/web2c/ptex-${VER_PTEX}
.else
WRKSRC=		${WRKDIR}/${TETEX_SRC}
.endif

WRKSRC_TETEX=	${WRKDIR}/${TETEX_SRC}
WRKSRC_PTEX=	${WRKDIR}/ptex-src-${VER_PTEX}

TETEX_SRC=	tetex-src-3.0
VER_PTEX=	${PORTVERSION}
VER_PTEXTEXMF=	2.4
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

INSTDIRS=	doc fonts jbibtex ptex
DOC_FILES=	COPYRIGHT COPYRIGHT.jis Changes.txt README.txt

MAPDIR=		${TEXMFDIR}/fonts/map/ptex/dvips
VFDIR=		${TEXMFDIR}/fonts/vf/ptex
TFMDIR=		${TEXMFDIR}/fonts/tfm/ptex

post-extract:
	${MV} ${WRKSRC_PTEX} ${WRKSRC}
	${MKDIR} ${WRKDIR}/texmf-tmp
	cd ${WRKDIR} && \
		${MV} ${INSTDIRS} texmf-tmp && \
		${RM} -f texmf-tmp/ptex/platex/base/.cvsignore

pre-configure:
	${SETENV} ${MAKE_ENV} ${MKTEXLSR} ${WRKDIR}/texmf-tmp
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
			--without-xdvik --without-oxdvik \
			--without-dvipsk --without-odvipsk \
			--without-x11 --without-dvipdfm \
			--without-pdftex --without-pdfetex --without-pdfxtex \
			--without-omega --without-eomega
			--without-etex && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

post-install:
	cd ${WRKDIR}/texmf-tmp && \
		${TAR} cf - ${INSTDIRS} | \
			(cd ${PREFIX}/${TEXMFDIR} && ${TAR} xf -)
	cd ${WRKDIR} && \
		${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/${TEXMFDIR}/doc/ptex
	${AWK} '/@comment INSTALL_DATA/{printf "${MKDIR} ${PREFIX}/%s && ${INSTALL_DATA} ${WRKDIR}/%s ${PREFIX}/%s\n",$$4,$$3,$$4}' < ${TMPPLIST} | ${SH}
	${MKDIR} ${PREFIX}/${TEXMFCONFIGDIR}/texconfig/ptex
	${INSTALL_DATA} ${FILESDIR}/tcfmgr.map \
		${PREFIX}/${TEXMFCONFIGDIR}/texconfig/ptex/tcfmgr.map
	${INSTALL_DATA} ${LOCALBASE}/${TEXMFDISTDIR}/web2c/updmap.cfg \
		${PREFIX}/${TEXMFDIR}/web2c/ptex/updmap.cfg
	${MKDIR} ${PREFIX}/${TEXMFCONFIGDIR}/web2c/ptex
	${INSTALL_DATA} ${LOCALBASE}/${TEXMFDISTDIR}/web2c/updmap.cfg \
		${PREFIX}/${TEXMFCONFIGDIR}/web2c/ptex/updmap.cfg
	${MKDIR} ${PREFIX}/${TEXMFCONFIGDIR}/dvips/ptex
.for F in dvips dvipdfm pdftex
	${MKDIR} ${PREFIX}/${FONTSMAPDIR}/${F}/updmap
	${MKDIR} ${PREFIX}/${FONTSMAPVARDIR}/${F}/updmap
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/updmap-ptex ${PREFIX}/${UPDMAPDIR}/updmap.ptex
	${MKTEXLSR}
	if ${PREFIX}/bin/kpsewhich -format=map psfonts_jp.map > /dev/null 2>&1; then \
		${SH} ${UPDMAP_SYS} --enable Map=psfonts_jp.map; \
	else \
		${SH} ${UPDMAP_SYS}; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
