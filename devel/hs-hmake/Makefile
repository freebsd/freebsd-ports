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

MAINTAINER=	mwest@uct.ac.za
COMMENT=	Intelligent compilation management tool for Haskell programs

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_GMAKE=	YES

.include <bsd.port.pre.mk>

do-install:
.if exists(${PREFIX}/bin/hmake) && !defined(OVERRIDE_HMAKE)
	@${ECHO} ""
	@${ECHO} "It seems that there is already a version of hmake installed on"
	@${ECHO} "this system. Please deinstall it, or define OVERRIDE_HMAKE to"
	@${ECHO} "override the installed version."
	@${ECHO} ""
	@${ECHO} "NOTE: hmake is part of nhc98"
	@${ECHO} ""
	@${FALSE}
.else
# cheat a bit, otherwise LIBDIR gets clobbered
	(cd ${WRKSRC} && ./configure --install)
.endif

MAN1=		hmake.1

.include <bsd.port.post.mk>
