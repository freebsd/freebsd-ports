# New ports collection makefile for:   xdvik + jp-patch
# Date created:        15 Jun 1998
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	xdvik
PORTVERSION=	${VERSION_XDVIK}.${VERSION_JPATCH}
PORTREVISION=	3
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xdvi
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-tetex
DISTNAME=	xdvik-${VERSION_XDVIK}

PATCH_SITES=	http://www.nn.iij4u.or.jp/~tutimura/tex/
PATCHFILES=	${PORTNAME}-${VERSION_XDVIK}-j${VERSION_JPATCH}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	DVI Previewer(kpathsearch) for X. + freetype support

BUILD_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	tetex-modesw:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMF}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		mktexlsr:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/${TEXMF}/fonts/tfm/ptex/min10.tfm:${PORTSDIR}/japanese/ptex-tetex \
		${X11BASE}/${TTFMINCHO}:${PORTSDIR}/japanese/kochi-ttfonts \
		${X11BASE}/${TTFGOTHIC}:${PORTSDIR}/japanese/kochi-ttfonts
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		wwwcore.1:${PORTSDIR}/www/libwww \
		t1.5:${PORTSDIR}/devel/t1lib

DIST_SUBDIR=	xdvik
USE_XLIB=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/${TEXMF:S,texmf$,,} \
		--enable-a4 --enable-shrink=${SHRINK} \
		--with-dvifilter=${DVIPS} \
		--enable-xdviprint=${PREFIX}/libexec/xdviprint \
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

VERSION_XDVIK=	22.40y1
VERSION_JPATCH=	1.21
LIBWWW_PREFIX?=	${LOCALBASE}
LIBT1_PREFIX?=	${LOCALBASE}

TEXMF=		share/texmf
XDVIDIR=	${TEXMF}/xdvi
TETEX_MODESW=	${LOCALBASE}/bin/tetex-modesw
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr

CIDFONTDIR=	${TEXMF}/dvipdfm/CIDFont
TTFMINCHO=	lib/X11/fonts/TrueType/kochi-mincho-subst.ttf
TTFGOTHIC=	lib/X11/fonts/TrueType/kochi-gothic-subst.ttf

VFONTCAPFT_SRC=	${WRKSRC}/vfontmap.freetype
VFONTCAPFT_SUB=	CIDFONTDIR=${LOCALBASE}/${CIDFONTDIR} \
		TTFMINCHO=${X11BASE}/${TTFMINCHO} \
		TTFGOTHIC=${X11BASE}/${TTFGOTHIC}

PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		MKTEXLSR=${MKTEXLSR}

PLIST_SUB=	TEXMF=${TEXMF}

.include <bsd.port.pre.mk>

BDPI?=		600
SHRINK?=	6
DVIPS?=		dvips
.if !defined(MF_MODE) || empty(MF_MODE)
MF_MODE!=	case ${BDPI} in\
		118) ${ECHO_CMD} bitgraph ;;\
		240) ${ECHO_CMD} canonlbp ;;\
		300) ${ECHO_CMD} cx ;;\
		360) ${ECHO_CMD} canonbjc ;;\
		400) ${ECHO_CMD} nexthi ;;\
		600) ${ECHO_CMD} ljfour ;;\
		*) ${ECHO_CMD} cx ;;\
		esac
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

pre-build:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}
	@(cd ${WRKSRC} && ${FIND} . -name '*.orig' -exec ${RM} -f {} \;)
	${SED} ${VFONTCAPFT_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/vfontmap.freetype \
		> ${VFONTCAPFT_SRC}

do-install:
	@(cd ${WRKSRC}/texk/xdvik ; ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

post-install:
	${RM} -f ${PREFIX}/${XDVIDIR}/vfontmap.freetype
	${RM} -f ${PREFIX}/${XDVIDIR}/vfontmap.vflib
	${INSTALL_DATA} \
		${VFONTCAPFT_SRC} \
		${PREFIX}/${XDVIDIR}/vfontmap.dist
	${INSTALL_DATA} \
		${VFONTCAPFT_SRC} \
		${PREFIX}/${XDVIDIR}/vfontmap
	${INSTALL_DATA} \
		${WRKSRC}/texk/xdvik/texmf/XDvi \
		${PREFIX}/${XDVIDIR}/XDvi.ptex-tetex
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/texk/xdvik/,} ${DOCSDIR}
.endif
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
