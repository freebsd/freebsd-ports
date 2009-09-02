# New ports collection makefile for:	hmake
# Date created:		27 November 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	hmake
PORTVERSION=	3.14
PORTREVISION=	3
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.haskell.org/hmake/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/hmake/ \
		http://www.cs.york.ac.uk/fp/hmake/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Intelligent compilation management tool for Haskell programs

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-readline>=1.0.1.0:${PORTSDIR}/devel/hs-readline
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_GMAKE=	YES

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	ARCH=ix86
.elif ${ARCH} == "amd64"
PLIST_SUB+=	ARCH=amd64
.endif

.if exists(${LOCALBASE}/lib/libreadline.so)
LIB_DEPENDS=	readline.6:${PORTSDIR}/devel/readline
.endif

do-install:
# cheat a bit, otherwise LIBDIR gets clobbered
	(cd ${WRKSRC} && ./configure --install)

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/runhs

MAN1=		hmake.1

CONFLICTS=	nhc98-[0-9]*

.include <bsd.port.post.mk>
