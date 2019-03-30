# $FreeBSD$

PORTNAME=	classy-prelude-conduit
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conduit instances for classy-prelude

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	classy-prelude>=0.12.0 conduit>=1.0 \
		conduit-combinators>=0.2.8 monad-control resourcet void

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
