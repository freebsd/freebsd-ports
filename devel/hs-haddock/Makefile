# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	haddock
PORTVERSION=	2.21.0
PORTREVISION=	2
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation-generation tool for Haskell libraries

LICENSE=	BSD3CLAUSE

USES=		cabal

USE_CABAL=	ghc-paths-0.1.0.9_4 haddock-api-2.21.0 haddock-library-1.7.0
SKIP_CABAL_PLIST=	yes

# new-cabal doesn't seem to support this yet
#CONFIGURE_ARGS+=	--program-suffix=-${PORTVERSION}

post-stage:
	${MV} ${STAGEDIR}/${PREFIX}/bin/haddock ${STAGEDIR}/${PREFIX}/bin/haddock-${PORTVERSION}

post-install-script:
	${ECHO_CMD} 'bin/haddock-${PORTVERSION}' >> ${TMPPLIST}

.include <bsd.port.mk>
