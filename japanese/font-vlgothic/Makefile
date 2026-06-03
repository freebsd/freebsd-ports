PORTNAME=	vlgothic
DISTVERSION=	20230918
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	https://vlgothic.dicey.org/releases/ \
		https://github.com/daisukesuzuki/VLGothic/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	VLGothic-${DISTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	VLGothic Japanese TrueType fonts
WWW=		https://vlgothic.dicey.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.en

USES=		fonts:fc tar:xz
FONTPATHSPEC=	${FONTNAME}:pri=60

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-install

WRKSRC=		${WRKDIR}/VLGothic

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-install

PORTDOCS=	Changelog LICENSE_E.mplus LICENSE_J.mplus \
		README README.sazanami README_J.mplus

OPTIONS_DEFINE=	DOCS

_CONF=		20-unhint-${FONTNAME}.conf 62-fonts-${FONTNAME}.conf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d
	${INSTALL_DATA} ${_CONF:S,^,${FILESDIR}/,} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.avail
	${RLN} ${_CONF:S,^,../conf.avail/,} \
	    ${STAGEDIR}${PREFIX}/etc/fonts/conf.d/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
