# $FreeBSD$

PORTNAME=	cabal-install
PORTVERSION=	1.16.0.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Command-line interface for Cabal and Hackage

LICENSE=	BSD

USE_CABAL=	network>=1 random>=1 HTTP>=4000.0.2 zlib>=0.4

STANDALONE=	yes
EXECUTABLE=	cabal-install

# Some magic to make `cabal` work with a custom toolchain
SUB_FILES=	cabal
SUB_LIST=	AR=${AR} CC=${CC} CPP=${CPP} LD=${LD} RANLIB=${RANLIB}

NO_STAGE=	yes
post-install::
	@${MV} ${PREFIX}/bin/cabal ${PREFIX}/bin/cabal-install
	${INSTALL_SCRIPT} ${WRKDIR}/cabal ${PREFIX}/bin

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
