PORTNAME=	ipamjm
PORTVERSION=	00601
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://mojikiban.ipa.go.jp/OSCDL/IPAmjMincho/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPAmj Mincho Japanese fonts

LICENSE=	IPAFONTLICv1.0
LICENSE_NAME=	IPA Font License Agreement v1.0
LICENSE_FILE=	${WRKSRC}/IPA_Font_License_Agreement_v1.0.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts:fc zip
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
PORTDOCS=	Readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ipamjm.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${FILESDIR}/20-unhint-${FONTNAME}.conf \
	    ${FILESDIR}/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${LN} -s -f ../conf.avail/20-unhint-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/20-unhint-${FONTNAME}.conf
	${LN} -s -f ../conf.avail/62-fonts-${FONTNAME}.conf \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/62-fonts-${FONTNAME}.conf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
