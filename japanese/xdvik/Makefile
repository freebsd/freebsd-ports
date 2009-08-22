# New ports collection makefile for:   xdvik + jp-patch
# Date created:        15 Jun 1998
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik
PORTVERSION=	${VERSION_XDVIK}.${VERSION_JPATCH}
PORTREVISION=	11
CATEGORIES=	japanese print
MASTER_SITES=	SF/xdvi/OldFiles
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTNAME=	xdvik-${VERSION_XDVIK}

PATCH_SITES=	http://www.nn.iij4u.or.jp/~tutimura/tex/
PATCHFILES=	${PORTNAME}-${VERSION_XDVIK}-j${VERSION_JPATCH}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X. + freetype support

BUILD_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMFDIR}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex \
		${LOCALBASE}/${MINCHO}:${PORTSDIR}/japanese/font-std \
		${LOCALBASE}/${GOTHIC}:${PORTSDIR}/japanese/font-std
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

DIST_SUBDIR=	xdvik
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/${TEXMFDIR:S,texmf$,,} \
		--enable-a4 --enable-shrink=${SHRINK} \
		--with-dvifilter=${DVIPS} \
		--enable-xdviprint=${PREFIX}/libexec/xdviprint \
		--enable-xdvietcdir=${PREFIX}/${XDVIETCDIR} \
		--enable-smallpanel --enable-zoombutton \
		--enable-gf \
		--with-system-wwwlib --with-libwww-libdir=${LIBWWW_PREFIX}/lib \
		--with-libwww-include=${LIBWWW_PREFIX}/include/w3c-libwww \
		--with-system-t1lib --with-t1lib-libdir=${LIBT1_PREFIX}/lib \
		--with-t1lib-include=${LIBT1_PREFIX}/include \
		--enable-vikey --disable-multiplatform \
		--with-vflib=vf2ft
CONFIGURE_ENV=	INSTALL="${INSTALL}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		XDEFS='-DMFMODE=\"${MF_MODE}\"' \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
SCRIPTS_ENV=	MV=${MV} SED=${SED}
PATCH_STRIP=	-p1

MAN1=		xdvi.1 xdvizilla.1 t1mapper.1

INSTALL_WRKSRC=	${WRKSRC}/texk/xdvik
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} \
		XDVIETCDIR=${XDVIETCDIR}
CONFLICTS=	xdvi-[0-9]* xdvi-*-[0-9]* xdvik-[0-9]*

VERSION_XDVIK=	22.40y1
VERSION_JPATCH=	1.21
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

TEXMFDIR=	share/texmf
TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCALDIR=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCALDIR}/ls-R
XDVIETCDIR=	${TEXMFDIR}/xdvi/ptex
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr

CIDFONTDIR=	${TEXMFDIR}/dvipdfm/CIDFont
MINCHO=		share/fonts/std.ja_JP/Ryumin-Light
GOTHIC=		share/fonts/std.ja_JP/GothicBBB-Medium
VFONTCAPFT_SRC=	${WRKSRC}/vfontmap.freetype
VFONTCAPFT_SUB=	CIDFONTDIR=${LOCALBASE}/${CIDFONTDIR} \
		MINCHO=${LOCALBASE}/${MINCHO} \
		GOTHIC=${LOCALBASE}/${GOTHIC}

.include <bsd.port.pre.mk>

BDPI?=		600
SHRINK?=	6
DVIPS?=		dvips
MF_MODES=	118:bitgraph \
		240:canonlbp \
		300:cx \
		360:canonbjc \
		400:nexthi \
		600:ljfour
.for B in ${BDPI}
MF_MODE?=	${MF_MODES:M${B}*:C/.*://}
.endfor
.if !defined(MF_MODE) || empty(MF_MODE)
MF_MODE=	cx
.endif

DOCS=	FAQ xdvi.icon CHANGES.xdvik-jp.html \
	README.xdvik-jp README.src-specials \
	README.t1fonts README.t1mapper \
	READMEs/ChangeLog.xdvik20a-j1.1 READMEs/ChangeLog.xdvik20c-j1.0 \
	READMEs/HEADERS.DOC READMEs/InternalVars \
	READMEs/README.jp+toc+hal2 READMEs/README.jp-patch \
	READMEs/README.markpage+toc+printdvi \
	READMEs/README.markpage+toc+printdvi+paper \
	READMEs/README.miyu-beta6 READMEs/README.ptex \
	READMEs/README.tasai-ussy READMEs/README.xdvik18f-j1.0.patch \
	READMEs/README.xdvik18f-j1.1p5.patch \
	READMEs/README.xdvik20a-j1.1.patch \
	READMEs/README.xdvik20c-j1.0+hal2+dvisel \
	READMEs/README.xdvik20c-j1.0p1.patch READMEs/README.vf2ft \
	READMEs/README.xdvik-22.15-j1.04.patch

PORTDOCS=	${DOCS:S,READMEs/,,}

pre-build:
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig' -exec ${RM} -f {} \;)
	${SED} ${VFONTCAPFT_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/vfontmap.freetype \
		> ${VFONTCAPFT_SRC}

post-install:
	${RM} -f ${PREFIX}/${XDVIETCDIR}/vfontmap.freetype
	${RM} -f ${PREFIX}/${XDVIETCDIR}/vfontmap.vflib
	${INSTALL_DATA} \
		${VFONTCAPFT_SRC} \
		${PREFIX}/${XDVIETCDIR}/vfontmap.dist
	${INSTALL_DATA} \
		${VFONTCAPFT_SRC} \
		${PREFIX}/${XDVIETCDIR}/vfontmap
	${INSTALL_DATA} \
		${WRKSRC}/texk/xdvik/texmf/XDvi \
		${PREFIX}/${XDVIETCDIR}/XDvi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/texk/xdvik && \
		${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	${MKTEXLSR}

.include <bsd.port.post.mk>
