# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	criterion
PORTVERSION=	1.2.1.0
CATEGORIES=	benchmarks haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Robust, reliable performance measurement and analysis

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson ansi-wl-pprint base-compat cassava code-page \
		exceptions Glob js-flot js-jquery microstache mtl mwc-random \
		optparse-applicative parsec statistics text transformers-compat \
		vector vector-algorithms

INSTALL_PORTEXAMPLES=	\
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DATADIR}

EXECUTABLE=	criterion-report

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
