# New ports collection makefile for: hs-criterion
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	criterion
PORTVERSION=	0.6.0.1
PORTREVISION=	2
CATEGORIES=	benchmarks haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Robust, reliable performance measurement and analysis

LICENSE=	BSD

USE_CABAL=	aeson>=0.3.2.12 hastache>=0.1.5 mtl>=2 mwc-random>=0.8.0.3 \
		parsec>=3.1.0 statistics>=0.10.0.0 vector>=0.7.1 \
		vector-algorithms>=0.4

INSTALL_PORTEXAMPLES=	\
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

INSTALL_PORTDATA= 	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
