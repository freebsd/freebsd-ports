# New ports collection makefile for:	buddha
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buddha
PORTVERSION=	1.1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.mu.oz.au/~bjpop/buddha/download/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A declarative debugger for Haskell 98

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_SIZE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

PLIST_SUB+=	BUDDHA_VERSION=${PORTVERSION:S/.r/-rc/}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502102
BROKEN=		"Does not compile"
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You need the profiling versions of GHC's libraries to build buddha."
	@${ECHO_CMD} "They are available, unless your GHC has been built with WITHOUT_PROFILE=yes."
	@${ECHO_CMD} ""

pre-build:
	@(cd ${WRKSRC} && ${GMAKE} depend)

.include <bsd.port.post.mk>
