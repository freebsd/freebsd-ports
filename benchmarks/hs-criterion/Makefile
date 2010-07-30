# New ports collection makefile for: hs-criterion
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	criterion
PORTVERSION=	0.5.0.3
CATEGORIES=	benchmarks haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Robust, reliable performance measurement and analysis for Haskell

USE_HACKAGE=	deepseq>=1.1.0.0 mwc-random>=0.7.0.0 statistics>=0.6.0.0 \
		vector>=0.6.0.2 vector-algorithms>=0.3.2

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	\
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

PORTDATA=		*
INSTALL_PORTDATA= 	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
