# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luajit
DISTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua

WRKSRC=		${WRKDIR}/LuaJIT-${DISTVERSION}
USES=		gmake
USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC}

PLIST_SUB+=	VERSION=${DISTVERSION}
BROKEN_powerpc64=	Not ported to powerpc64 upstream

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mmips*} || ${ARCH:Msparc*}
USE_GCC=yes
.endif

post-install:
	${LN} -sf ${PORTNAME}-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
