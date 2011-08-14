# New ports collection makefile for: hs-criterion
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	criterion
PORTVERSION=	0.5.0.10
PORTREVISION=	5
CATEGORIES=	benchmarks haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Robust, reliable performance measurement and analysis for Haskell

LICENSE=	BSD

USE_CABAL=	deepseq>=1.1 mtl mwc-random>=0.8.0.3 parallel parsec>=3.1 \
		statistics>=0.8.0.5 vector>=0.7 vector-algorithms>=0.4

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	\
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

PORTDATA=		*
INSTALL_PORTDATA= 	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
