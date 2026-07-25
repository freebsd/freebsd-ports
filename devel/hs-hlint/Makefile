PORTNAME=	hlint
PORTVERSION=	3.10
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Source code suggestions
WWW=		https://github.com/ndmitchell/hlint

LICENSE=	BSD3CLAUSE

USES=		cabal

post-patch:
	${REINPLACE_CMD} 's|jobs: 1|jobs: 2|' ${CABAL_HOME}/.cabal/config

.include <bsd.port.mk>
