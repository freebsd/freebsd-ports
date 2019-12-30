# Created by: The 244th namelessness at 2ch.net
# $FreeBSD$

PORTNAME=	mplus
PORTVERSION=	0.6.3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	OSDN/${PORTNAME}-fonts/62344/
PKGNAMEPREFIX=	ja-font-
PKGNAMESUFFIX=	-outline
DISTNAME=	${PORTNAME}-TESTFLIGHT-063a

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	M+ Outline Fonts

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE_E

RUN_DEPENDS=	mkfontscale>=0:x11-fonts/mkfontscale \
		mkfontscale:x11-fonts/mkfontscale

USES=		fonts:fc tar:xz
FONTNAME=	${PORTNAME}${PKGNAMESUFFIX}
FONTPATHSPEC=	${FONTNAME}:pri=60
NO_BUILD=	yes
NO_ARCH=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
PLIST_SUB=	FONTSDIR="${FONTSDIR}"
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	README_E LICENSE_J README_J

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
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
