# New ports collection makefile for:	buddha
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buddha
PORTVERSION=	1.2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.mu.oz.au/~bjpop/buddha/download/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A declarative debugger for Haskell 98

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	buddha.1

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You need the profiling versions of GHC's libraries to build buddha."
	@${ECHO_CMD} "They are available, unless your GHC has been built with WITHOUT_PROFILE=yes."
	@${ECHO_CMD} ""

.include <bsd.port.mk>
