# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	criterion
PORTVERSION=	1.1.0.0
CATEGORIES=	benchmarks haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Robust, reliable performance measurement and analysis

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson>=0.8 ansi-wl-pprint>=0.6.7.2 cassava>=0.3.0.0 \
		Glob>=0.7.2 hastache>=0.6.0 mtl>=2 mwc-random>=0.8.0.3 \
		optparse-applicative>=0.11 parsec>=3.1.0 statistics>=0.13.2.1 \
		text>=0.11 vector>=0.7.1 vector-algorithms>=0.4

INSTALL_PORTEXAMPLES=	\
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
