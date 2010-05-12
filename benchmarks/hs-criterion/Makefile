# New ports collection makefile for: hs-criterion
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	criterion
PORTVERSION=	0.4.1.0
CATEGORIES=	benchmarks haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	Robust, reliable performance measurement and analysis for Haskell

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	deepseq>=1.1.0.0 statistics>=0.3.5 uvector>=0.1.0.5 \
		uvector-algorithms>=0.2

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	\
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

PORTDATA=		*
INSTALL_PORTDATA= 	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>