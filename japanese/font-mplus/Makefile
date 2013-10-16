# Created by: The 244th namelessness at 2ch.net
# $FreeBSD$

PORTNAME=	mplus
PORTVERSION=	2.2.4.055
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/${PORTNAME}-fonts/5030:bitmap \
		SFJP/${PORTNAME}-fonts/6650:outline
PKGNAMEPREFIX=	ja-font-
DISTFILES=	${PORTNAME}_bitmap_fonts-2.2.4.tar.gz:bitmap \
		${PORTNAME}-TESTFLIGHT-055.tar.xz:outline

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	M+ Bitmap and Outline Fonts

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_XZ=		yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR} \
		FONTSALIAS=${DATADIR}/bitmap/fonts.alias
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}_bitmap_fonts-2.2.4
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	INSTALL_E.bitmap LICENSE_E.bitmap README_E.bitmap \
		INSTALL_J.bitmap LICENSE_J.bitmap README_J.bitmap \
		LICENSE_E.outline README_E.outline \
		LICENSE_J.outline README_J.outline

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	cd ${WRKDIR}/${PORTNAME}_bitmap_fonts-2.2.4 && \
	    ${CAT} fonts_e/fonts.alias fonts_e/euro/fonts.alias \
	    fonts_j/fonts.alias | ${SORT} -r > ${WRKDIR}/fonts.alias

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/TTF ${STAGEDIR}${DATADIR}/bitmap

do-install: do-install-bitmap do-install-outline

do-install-bitmap:
	cd ${WRKDIR}/${PORTNAME}_bitmap_fonts-2.2.4 && \
	    ${SETENV} DESTDIR="${STAGEDIR}${DATADIR}/bitmap" \
	    ${SH} ${WRKDIR}/${PORTNAME}_bitmap_fonts-2.2.4/install_mplus_fonts
	${INSTALL_DATA} ${WRKDIR}/fonts.alias ${STAGEDIR}${DATADIR}/bitmap
	${MKDIR} ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/${PORTNAME}
	cd ${STAGEDIR}/${PREFIX}/${LOCAL_FONTSDIR}/${PORTNAME} && \
	    ${LN} -s -f ../${LOCAL_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/bitmap/*.pcf.gz .
	${MKDIR} ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/misc
	cd ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/misc && \
	    ${LN} -s -f ../${X_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/bitmap/*.pcf.gz .

do-install-outline:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-TESTFLIGHT-055/*.ttf \
	    ${STAGEDIR}${DATADIR}/TTF
	${MKDIR} ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF
	cd ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${LOCAL_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/TTF/*.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF
	cd ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${X_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/TTF/*.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf

post-su-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for F in ${PORTDOCS:M*.bitmap:S,.bitmap$,,}; do \
		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_bitmap_fonts-2.2.4/$${F} ${STAGEDIR}${DOCSDIR}/$${F}.bitmap; \
	done
	for F in ${PORTDOCS:M*.outline:S,.outline$,,}; do \
		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-TESTFLIGHT-055/$${F} ${STAGEDIR}${DOCSDIR}/$${F}.outline; \
	done
.endif

.include <bsd.port.mk>
