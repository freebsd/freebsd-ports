# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luajit
DISTVERSION=	2.0.3
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/
DISTNAME=	LuaJIT-${DISTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Just-In-Time Compiler for Lua

WRKSRC=		${WRKDIR}/LuaJIT-${DISTVERSION}
USES=		gmake
USE_LDCONFIG=	yes

PLIST_SUB+=	VERSION=${DISTVERSION}

post-install:
	${LN} -sf ${PREFIX}/bin/${PORTNAME}-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
