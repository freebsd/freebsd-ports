# New ports collection makefile for: hs-hslogger
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hslogger
PORTVERSION=	1.1.0
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Versatile logging framework for Haskell

CABAL_SETUP=	Setup.hs

post-patch:
#
# Work around features unsupported by current Haddock.  This shall be
# removed on update.
#
	@${REINPLACE_CMD} 's|-- ^|--|' \
		${WRKSRC}/src/System/Log.hs \
		${WRKSRC}/src/System/Log/Logger.hs \
		${WRKSRC}/src/System/Log/Formatter.hs \
		${WRKSRC}/src/System/Log/Handler/Growl.hs \
		${WRKSRC}/src/System/Log/Handler/Syslog.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
