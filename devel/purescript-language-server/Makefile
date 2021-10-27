PORTNAME=	purescript-language-server
PORTVERSION=	0.15.7
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/nwolverson/${PORTNAME}/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}.js
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	LSP provider implementation for PureScript language

LICENSE=	MIT

RUN_DEPENDS=	node:www/node

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
