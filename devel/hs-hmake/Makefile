# New ports collection makefile for:	hmake
# Date created:		27 November 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	hmake
PORTVERSION=	3.08
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/hmake/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/hmake/ \
		http://www.cs.york.ac.uk/fp/hmake/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Intelligent compilation management tool for Haskell programs

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_GMAKE=	YES

do-install:
# cheat a bit, otherwise LIBDIR gets clobbered
	(cd ${WRKSRC} && ./configure --install)

MAN1=		hmake.1

CONFLICTS=	nhc98-*

.include <bsd.port.mk>
