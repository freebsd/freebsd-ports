# Created by: NIIMI Satoshi <sa2c@sa2c.net>
# $FreeBSD$

PORTNAME=	vlgothic
PORTVERSION=	20141206
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SFJP/vlgothic/62375
PKGNAMEPREFIX=	ja-font-
DISTNAME=	VLGothic-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	VLGothic Japanese TrueType fonts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.en

USES=		fonts:fc tar:xz
FONTNAME=	TTF
NO_ARCH=	yes
NO_BUILD=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install
SUB_FILES=	pkg-install
DATADIR=	${PREFIX}/share/font-${PORTNAME}
PORTDOCS=	Changelog LICENSE_E.mplus LICENSE_J.mplus \
		README README.sazanami README_J.mplus
WRKSRC=		${WRKDIR}/VLGothic

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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
