PORTNAME=	migu
DISTVERSION=	1.0.20231123
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://github.com/itouhiro/mixfont-mplus-ipa/releases/download/v${_1VER:C,(202[0-9]),\1.,}/:1ver \
		https://github.com/itouhiro/mixfont-mplus-ipa/releases/download/v${_2VER:C,(202[0-9]),\1.,}/:2ver
PKGNAMEPREFIX=	ja-font-
DISTFILES=	${PORTNAME}-1p-${_1VER}${EXTRACT_SUFX}:1ver \
		${PORTNAME}-1c-${_1VER}${EXTRACT_SUFX}:1ver \
		${PORTNAME}-1m-${_1VER}${EXTRACT_SUFX}:1ver \
		${PORTNAME}-2m-${_2VER}${EXTRACT_SUFX}:2ver

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Another Japanese font set based on MigMix
WWW=		https://itouhiro.github.io/mixfont-mplus-ipa/migu/

LICENSE=	IPAFONTLICv1.0
LICENSE_NAME=	IPA Font License Agreement v1.0
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-2m-${_2VER}/ipag00303/IPA_Font_License_Agreement_v1.0.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts:fc zip
FONTPATHSPEC=	${FONTNAME}:pri=60

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-install

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
PORTDOCS=	${PORTNAME}-README.txt Readme_ipag00303.txt

OPTIONS_DEFINE=	DOCS

_1VER=		20200307
_2VER=		${DISTVERSION:E}
_CONF=		20-unhint-${FONTNAME}.conf 62-fonts-${FONTNAME}.conf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-*/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${_CONF:S,^,${FILESDIR}/,} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${RLN} ${_CONF:S,^,../conf.avail/,} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${PORTNAME}-2m-${_2VER}/ && \
	    ${INSTALL_DATA} ${PORTDOCS:S,^Readme,ipag00303/Readme,} \
	    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
