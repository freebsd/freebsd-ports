# $FreeBSD$

PORTNAME=	project-template
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Specify Haskell project templates and generate files

LICENSE=	BSD

USE_CABAL=	base64-bytestring base64-conduit classy-prelude>=0.4 \
		conduit>=0.5.4 mtl>=2.0 resourcet>=0.4.3 system-fileio>=0.3 \
		system-filepath>=0.4 text>=0.11 transformers>=0.2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
