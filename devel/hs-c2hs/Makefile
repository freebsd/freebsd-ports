# New ports collection makefile for:   c2hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c2hs
PORTVERSION=	0.10.17
CATEGORIES=	devel
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/c2hs/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_SUB=	C2HS_VERSION=${PORTVERSION}

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package

.if defined(WITH_PROFILE)
CONFIGURE_ARGS+=	--enable-prof
.endif

MAN1=	c2hs-config.1 c2hs.1

.if !defined(WITH_PROFILE)
pre-everything::
	@${ECHO_CMD} "To enable profiling support define WITH_PROFILE."
	@${ECHO_CMD} "This requires ghc with profiling libraries."
.endif

post-build:
	@(cd ${WRKSRC}/doc/c2hs && ${GMAKE} man1/c2hs-config.1 man1/c2hs.1)

post-install:
	@(cd ${WRKSRC}/doc/c2hs/man1 && \
		 ${INSTALL_MAN} c2hs-config.1 c2hs.1 ${MANPREFIX}/man/man1)

.include <bsd.port.mk>
