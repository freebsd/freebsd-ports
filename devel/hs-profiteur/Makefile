PORTNAME=	profiteur
DISTVERSION=	0.4.7.1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Treemap visualiser for GHC .prof files
WWW=		https://github.com/jaspervdj/profiteur/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ghc-9.8.4:lang/ghc98

USES=		cabal

CABAL_WRAPPER_SCRIPTS=		${CABAL_EXECUTABLES}
profiteur_DATADIR_VARS=		js-jquery

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${CABAL_DEPSDIR}/js-jquery-3.7.1/javascript/jquery-3.7.1.min.js ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
