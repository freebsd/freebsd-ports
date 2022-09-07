PORTNAME=	purescript-language-server
PORTVERSION=	0.16.6
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/nwolverson/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}.js
EXTRACT_SUFX=
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
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
