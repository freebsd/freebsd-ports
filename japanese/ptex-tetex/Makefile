# New ports collection makefile for:	ptex-tetex
# Date created:		9 Feb 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	ptex-tetex
PORTVERSION=	3.1.5
PORTREVISION=	0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://sunsite.informatik.rwth-aachen.de/pub/comp/tex/teTeX/2.0/distrib/ \
		${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/:1 \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/jvf/:2
MASTER_SITE_SUBDIR=	systems/unix/teTeX/2.0/distrib
PKGNAMEPREFIX=	ja-
DISTFILES=	ptex-src-${VER_PTEX}${EXTRACT_SUFX}:1 \
		ptex-texmf-${VER_PTEXTEXMF}${EXTRACT_SUFX}:1 \
		tetex-src-${VER_TETEX}${EXTRACT_SUFX} \
		jis${EXTRACT_SUFX}:2 morisawa${EXTRACT_SUFX}:2
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	ASCII Japanese pTeX which supports teTeX distribution

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/base/latex.ltx:${PORTSDIR}/print/teTeX-latex2e
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFLOCAL}/tex/latex/base/latex.ltx:${PORTSDIR}/print/teTeX-latex2e
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
MAKE_ENV=	TEXMFLOCAL=${WRKDIR}/texmf-tmp \
		TEXMFDUMP=${LOCALBASE}/${TEXMFLOCAL}
.endif
ALL_TARGET=	default
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} TEXMFDIR=${TEXMFDIR}
CONFLICTS=	ja-ptex-base-[0-9]*
.if !make(do-patch)
WRKSRC=		${WRKDIR}/tetex-src-${VER_TETEX}/texk/web2c/ptex-${VER_PTEX}
.else
WRKSRC=		${WRKDIR}/tetex-src-${VER_TETEX}
.endif

WRKSRC_TETEX=	${WRKDIR}/tetex-src-${VER_TETEX}
WRKSRC_PTEX=	${WRKDIR}/ptex-src-${VER_PTEX}

VER_TETEX=	2.0.2
VER_PTEX=	${PORTVERSION}
VER_PTEXTEXMF=	2.2
KANJICODE?=	euc
TEXMFDIR?=	share/texmf
TEXMFLOCAL?=	share/texmf-local
TEXMFLOCAL_LSR?=${LOCALBASE}/${TEXMFLOCAL}/ls-R
TEXMFCNF?=	${PREFIX}/${TEXMFDIR}/web2c/texmf.cnf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr
LIBPNG_PREFIX?=	${LOCALBASE}
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

INSTDIRS=	doc fonts jbibtex ptex
DOC_FILES=	COPYRIGHT COPYRIGHT.jis Changes.txt README.txt

MAPDIR=		${PREFIX}/${TEXMFDIR}/dvips-ptex
MAPFILES=	morisawa/morisawa.map jis/jis.map

VFDIR=		${PREFIX}/${TEXMFDIR}/fonts/vf/ptex
VFFILES=	jis/vf/jis.vf jis/vf/jisg.vf \
		jis/vf/jis-v.vf jis/vf/jisg-v.vf \
		jis/vf/jisgn-v.vf jis/vf/jisgn.vf \
		jis/vf/jisn-v.vf jis/vf/jisn.vf \
		morisawa/vf/FutoGoB101-Bold-H.vf \
		morisawa/vf/FutoGoB101-Bold-J.vf \
		morisawa/vf/FutoGoB101-Bold-V.vf \
		morisawa/vf/FutoMinA101-Bold-H.vf \
		morisawa/vf/FutoMinA101-Bold-J.vf \
		morisawa/vf/FutoMinA101-Bold-V.vf \
		morisawa/vf/GothicBBB-Medium-H.vf \
		morisawa/vf/GothicBBB-Medium-J.vf \
		morisawa/vf/GothicBBB-Medium-V.vf \
		morisawa/vf/Jun101-Light-H.vf \
		morisawa/vf/Jun101-Light-J.vf \
		morisawa/vf/Jun101-Light-V.vf \
		morisawa/vf/Ryumin-Light-H.vf \
		morisawa/vf/Ryumin-Light-J.vf \
		morisawa/vf/Ryumin-Light-V.vf

TFMDIR=		${PREFIX}/${TEXMFDIR}/fonts/tfm/ptex
TFMFILES=	jis/tfm/ptex/jis.tfm jis/tfm/ptex/jisg.tfm \
		jis/tfm/ptex/jis-v.tfm jis/tfm/ptex/jisg-v.tfm \
		jis/tfm/ptex/jisgn-v.tfm jis/tfm/ptex/jisgn.tfm \
		jis/tfm/ptex/jisn-v.tfm jis/tfm/ptex/jisn.tfm \
		morisawa/tfm/dvips/futogo-b-v.tfm \
		morisawa/tfm/dvips/futogo-b.tfm \
		morisawa/tfm/dvips/futomin-b-v.tfm \
		morisawa/tfm/dvips/futomin-b.tfm \
		morisawa/tfm/dvips/gtbbb-m-v.tfm \
		morisawa/tfm/dvips/gtbbb-m.tfm \
		morisawa/tfm/dvips/jun101-l-v.tfm \
		morisawa/tfm/dvips/jun101-l.tfm \
		morisawa/tfm/dvips/ryumin-l-v.tfm \
		morisawa/tfm/dvips/ryumin-l.tfm \
		morisawa/tfm/ptex/FutoGoB101-Bold-H.tfm \
		morisawa/tfm/ptex/FutoMinA101-Bold-H.tfm \
		morisawa/tfm/ptex/GothicBBB-Medium-H.tfm \
		morisawa/tfm/ptex/Jun101-Light-H.tfm \
		morisawa/tfm/ptex/Ryumin-Light-H.tfm \
		morisawa/tfm/ptex/FutoGoB101-Bold-J.tfm \
		morisawa/tfm/ptex/FutoMinA101-Bold-J.tfm \
		morisawa/tfm/ptex/GothicBBB-Medium-J.tfm \
		morisawa/tfm/ptex/Jun101-Light-J.tfm \
		morisawa/tfm/ptex/Ryumin-Light-J.tfm \
		morisawa/tfm/ptex/FutoGoB101-Bold-V.tfm \
		morisawa/tfm/ptex/FutoMinA101-Bold-V.tfm \
		morisawa/tfm/ptex/GothicBBB-Medium-V.tfm \
		morisawa/tfm/ptex/Jun101-Light-V.tfm \
		morisawa/tfm/ptex/Ryumin-Light-V.tfm

post-extract:
	${MV} ${WRKSRC_PTEX} ${WRKSRC}
	${MKDIR} ${WRKDIR}/texmf-tmp
	cd ${WRKDIR} && \
		${MV} ${INSTDIRS} texmf-tmp && \
		${RM} -f ptex/platex/base/.cvsignore

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
			--without-x11 --without-dvipdfm --without-omega \
			--without-pdftex --without-pdfetex \
			--with-etex=no && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}

post-install:
	cd ${WRKDIR}/texmf-tmp && \
		${TAR} cf - ${INSTDIRS} | \
			(cd ${PREFIX}/${TEXMFDIR} && ${TAR} xf -)
	cd ${WRKDIR} && \
		${INSTALL_DATA} ${DOC_FILES} ${PREFIX}/${TEXMFDIR}/doc/ptex
.for D in MAP VF TFM
	${MKDIR} ${${D}DIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${${D}FILES} ${${D}DIR}
.endfor
	${MKTEXLSR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
