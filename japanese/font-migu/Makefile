# $FreeBSD$

PORTNAME=	migu
PORTVERSION=	1.0.20130617
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	mix-mplus-ipa/59022
PKGNAMEPREFIX=	ja-font-
DISTFILES=	${PORTNAME}-1p-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-1c-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-1m-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-2m-${PORTVERSION:E}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Another Japanese font set based on MigMix

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
SUB_LIST=	X_FONTSDIR=${PREFIX}/${X_FONTSDIR}
PLIST_SUB=	X_FONTSDIR=${X_FONTSDIR} \
		LOCAL_FONTSDIR=${LOCAL_FONTSDIR}
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt Readme_ipag00303.txt \
		migu-README.txt

LOCAL_FONTSDIR=	share/fonts
X_FONTSDIR=	lib/X11/fonts

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	cd ${WRKDIR}/${PORTNAME}-1p-${PORTVERSION:E}/ && \
	    ${INSTALL_DATA} ipag00303/*.txt \
		${PORTNAME}-README.txt \
		${WRKDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
	    ${WRKDIR}/${PORTNAME}-1p-${PORTVERSION:E}/*.ttf \
	    ${WRKDIR}/${PORTNAME}-1c-${PORTVERSION:E}/*.ttf \
	    ${WRKDIR}/${PORTNAME}-1m-${PORTVERSION:E}/*.ttf \
	    ${WRKDIR}/${PORTNAME}-2m-${PORTVERSION:E}/*.ttf \
	    ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF
	cd ${STAGEDIR}${PREFIX}/${LOCAL_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${LOCAL_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/migu*.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF
	cd ${STAGEDIR}${PREFIX}/${X_FONTSDIR}/TTF && ${LN} -s -f \
	    ../${X_FONTSDIR:C,[^/]+,..,g}/${DATADIR_REL}/migu*.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

post-su-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
