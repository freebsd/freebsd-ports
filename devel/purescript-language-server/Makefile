PORTNAME=	purescript-language-server
PORTVERSION=	0.18.4
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/nwolverson/${PORTNAME}/releases/download/v${PORTVERSION}/${PORTNAME}.js?dummy=/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.js
EXTRACT_ONLY=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	LSP provider implementation for PureScript language
WWW=		https://github.com/nwolverson/purescript-language-server/

LICENSE=	MIT

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
