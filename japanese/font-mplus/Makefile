# New ports collection makefile for:	M+ Fonts
# Date created:		July 17 2002
# Whom:			The 244th namelessness at 2ch.net
#
# $FreeBSD$
#

PORTNAME=	font-mplus
PORTVERSION=	2.2.4.023
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://downloads.sourceforge.jp/mplus-fonts/5030/:bitmap \
		http://downloads.sourceforge.jp/mplus-fonts/6650/:outline \
		http://wids.net/archive/mplusfonts/distfiles/
DISTFILES=	mplus_bitmap_fonts-2.2.4${EXTRACT_SUFX}:bitmap \
		mplus-TESTFLIGHT-023${EXTRACT_SUFX}:outline

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	M+ Bitmap and Outline Fonts

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR} \
		FONTSALIAS=${DATADIR}/bitmap/fonts.alias
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
PATCH_WRKSRC=	${WRKDIR}/mplus_bitmap_fonts-2.2.4

PORTDOCS=	INSTALL_E.bitmap LICENSE_E.bitmap README_E.bitmap \
		INSTALL_J.bitmap LICENSE_J.bitmap README_J.bitmap \
		LICENSE_E.outline README_E.outline \
		LICENSE_J.outline README_J.outline

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

post-extract:
	cd ${WRKDIR}/mplus_bitmap_fonts-2.2.4 && \
		${CAT} fonts_e/fonts.alias fonts_e/euro/fonts.alias \
		fonts_j/fonts.alias | ${SORT} -r > ${WRKDIR}/fonts.alias

pre-su-install:
	${MKDIR} ${DATADIR}/TTF ${DATADIR}/bitmap

do-install: do-install-bitmap do-install-outline

do-install-bitmap:
	cd ${WRKDIR}/mplus_bitmap_fonts-2.2.4 && \
		${SETENV} DESTDIR="${DATADIR}/bitmap" \
		${SH} ${WRKDIR}/mplus_bitmap_fonts-2.2.4/install_mplus_fonts
	${INSTALL_DATA} ${WRKDIR}/fonts.alias ${DATADIR}/bitmap
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/mplus
	${LN} -s -f ${DATADIR}/bitmap/*.pcf.gz ${LOCALBASE}/${LOCAL_FONTSDIR}/mplus/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/misc
	${LN} -s -f ${DATADIR}/bitmap/*.pcf.gz ${LOCALBASE}/${X_FONTSDIR}/misc/

do-install-outline:
	${INSTALL_DATA} ${WRKDIR}/mplus-TESTFLIGHT-023/*.ttf ${DATADIR}/TTF
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/TTF/*.ttf ${LOCALBASE}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${LOCALBASE}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/TTF/*.ttf ${LOCALBASE}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-mplus.conf \
		${FILESDIR}/62-fonts-mplus.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-mplus.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-mplus.conf
	${LN} -s -f ../conf.avail/62-fonts-mplus.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-mplus.conf

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for F in ${PORTDOCS:M*.bitmap:S,.bitmap$,,}; do \
		${INSTALL_DATA} ${WRKDIR}/mplus_bitmap_fonts-2.2.4/$${F} ${DOCSDIR}/$${F}.bitmap; \
	done
	for F in ${PORTDOCS:M*.outline:S,.outline$,,}; do \
		${INSTALL_DATA} ${WRKDIR}/mplus-TESTFLIGHT-023/$${F} ${DOCSDIR}/$${F}.outline; \
	done
.endif

.include <bsd.port.mk>
