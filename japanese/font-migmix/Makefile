# $FreeBSD$

PORTNAME=	migmix
PORTVERSION=	1.0.20130617
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	OSDN/mix-mplus-ipa/59021
PKGNAMEPREFIX=	ja-font-
DISTFILES=	${PORTNAME}-1m-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-2m-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-1p-${PORTVERSION:E}${EXTRACT_SUFX} \
		${PORTNAME}-2p-${PORTVERSION:E}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mixed Japanese font with IPA Gothic and M-plus outline

USES=		fonts:fc zip
FONTNAME=	TTF
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	IPA_Font_License_Agreement_v1.0.txt Readme_ipag00303.txt \
		migmix-README.txt

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKDIR}/${PORTNAME}-1m-${PORTVERSION:E}/ && \
	    ${INSTALL_DATA} ipag00303/*.txt \
		migmix-README.txt \
		${WRKDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} \
	    ${WRKDIR}/${PORTNAME}-1m-${PORTVERSION:E}/*.ttf \
	    ${WRKDIR}/${PORTNAME}-2m-${PORTVERSION:E}/*.ttf \
	    ${WRKDIR}/${PORTNAME}-1p-${PORTVERSION:E}/*.ttf \
	    ${WRKDIR}/${PORTNAME}-2p-${PORTVERSION:E}/*.ttf \
	    ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && ${LN} -s -f \
	    ../../../${DATADIR_REL}/migmix*.ttf .
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${PORTNAME}.conf \
	    ${FILESDIR}/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${PORTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${PORTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${PORTNAME}.conf

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
