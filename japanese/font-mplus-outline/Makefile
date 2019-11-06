# Created by: The 244th namelessness at 2ch.net
# $FreeBSD$

PORTNAME=	mplus
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	OSDN/${PORTNAME}-fonts/62344/
PKGNAMEPREFIX=	ja-font-
PKGNAMESUFFIX=	-outline
DISTNAME=	${PORTNAME}-TESTFLIGHT-060

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	M+ Outline Fonts

BROKEN=		unfetchable

RUN_DEPENDS=	mkfontscale>=0:x11-fonts/mkfontscale \
		mkfontscale:x11-fonts/mkfontscale

USES=		fonts:fc tar:xz
NO_BUILD=	yes
NO_ARCH=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	LICENSE_E README_E LICENSE_J README_J

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${STAGEDIR}${FONTSDIR} && ${LN} -s -f \
	    ../../../${DATADIR_REL}/*.ttf .
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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
