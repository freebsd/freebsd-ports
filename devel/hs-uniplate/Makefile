# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	uniplate
PORTVERSION=	1.6.10
PORTREVISION=	3
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Help writing simple, concise, and fast generic operations

LICENSE=	BSD

USE_CABAL=	hashable>=1.1.2.3 syb unordered-containers>=0.2.1

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/uniplate.htm ${DATADIR}

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
