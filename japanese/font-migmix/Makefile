# $FreeBSD$

PORTNAME=	migmix
PORTVERSION=	1.0.20130430
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/mix-mplus-ipa/58721
PKGNAMEPREFIX=	ja-font-
DISTFILES=	${PORTNAME}-1m-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-2m-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-1p-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-2p-${PORTVERSION:E}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mixed Japanese font with IPA Gothic and M-plus outline

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt Readme_ipag00303.txt \
		migmix-README.txt
LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	cd ${WRKDIR}/${PORTNAME}-1m-${PORTVERSION:E}/ && \
		${INSTALL_DATA} ipag00303/*.txt \
			migmix-README.txt \
			${WRKDIR}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}-1m-${PORTVERSION:E}/*.ttf \
		${WRKDIR}/${PORTNAME}-2m-${PORTVERSION:E}/*.ttf \
		${WRKDIR}/${PORTNAME}-1p-${PORTVERSION:E}/*.ttf \
		${WRKDIR}/${PORTNAME}-2p-${PORTVERSION:E}/*.ttf \
		${DATADIR}
	${MKDIR} ${PREFIX}/${LOCAL_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/migmix*.ttf \
		${PREFIX}/${LOCAL_FONTSDIR}/TTF/
	${MKDIR} ${PREFIX}/${X_FONTSDIR}/TTF
	${LN} -s -f ${DATADIR}/migmix*.ttf \
		${PREFIX}/${X_FONTSDIR}/TTF/
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
		${FILESDIR}/62-fonts-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
		${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	${LOCALBASE}/bin/fc-cache -s -f -v ${PREFIX}/${X_FONTSDIR}/TTF
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
