PORTNAME=	tickrs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.9
PORTREVISION=	18
CATEGORIES=	finance

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Realtime ticker data in your terminal
WWW=		https://github.com/tarkah/tickrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	tarkah

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
