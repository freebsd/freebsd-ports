# New ports collection makefile for:	hmake
# Date created:		27 November 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	hmake
PORTVERSION=	2.03
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/hmake/

MAINTAINER=	mwest@uct.ac.za

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

BROKEN=		"Does not build"

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_GMAKE=	YES

# cheat a bit, otherwise LIBDIR gets clobbered
do-install:
	(cd ${WRKSRC} && ./configure --install)

MAN1=		hmake.1

.include <bsd.port.mk>
