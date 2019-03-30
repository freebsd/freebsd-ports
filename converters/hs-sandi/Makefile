# $FreeBSD$

PORTNAME=	sandi
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	converters haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Data encoding library

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

CONFLICTS_INSTALL=	hs-dataenc-[0-9]*

USE_CABAL=	conduit exceptions stringsearch

post-extract:
	${ECHO} "import Distribution.Simple" > ${WRKSRC}/Setup.hs
	${ECHO} "main = defaultMain" >>  ${WRKSRC}/Setup.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
