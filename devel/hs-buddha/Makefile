# New ports collection makefile for:	buddha
# Date created:				28 January 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buddha
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.cs.mu.oz.au/~bjpop/buddha/download/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A declarative debugger for Haskell 98

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

USE_SIZE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

PLIST_SUB+=	BUDDHA_VERSION=${PORTVERSION:S/.r/-rc/}

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You need the profiling versions of GHC's libraries to build buddha."
	@${ECHO_CMD} "They are available, unless your GHC has been built with WITHOUT_PROFILE=yes."
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's/-package lang/-package lang -package text/' \
		${WRKSRC}/transform/Makefile.in

pre-build:
	@(cd ${WRKSRC} && ${GMAKE} depend)

.include <bsd.port.mk>
