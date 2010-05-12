# New ports collection makefile for: hs-haddock-docs
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	haddock
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Documentation for Haddock

USE_AUTOTOOLS=	autoconf:262:env

DOCUMENTATION=	yes
XMLDOCS=	doc/haddock:users_guide
SHOW_PKGMSG=	yes

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if ${PORT_HADDOCK} == 11
ECHO_MSG=	${PRINTF} "%b"
IGNORE+=	\n\t The ${LOCALBASE}/bin/haddock executable was already installed\n
IGNORE+=	\t by the lang/ghc port, setting the option WITH_HADDOCK.\n
IGNORE+=	\t You have to reinstall this last one with the right option\n
IGNORE+=	\t WITHOUT_HADDOCK.\n\c
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
