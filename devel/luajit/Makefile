# New ports collection makefile for:	luajit
# Date created:		08 Jan 2012
# Whom:			osa
#
# $FreeBSD$
#

PORTNAME=	luajit
DISTVERSION=	2.0.0-beta9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://luajit.org/download/
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A Just-In-Time Compiler for Lua

WRKSRC=		${WRKDIR}/LuaJIT-${DISTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	"-I../"

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		luajit.1
.endif

pre-build:
	${CP} ${FILESDIR}/unwind.h ${WRKSRC}

post-install:
	${LN} -sf ${PREFIX}/bin/${PORTNAME}-${DISTVERSION} \
		${PREFIX}/bin/${PORTNAME}
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
