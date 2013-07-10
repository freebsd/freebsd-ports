# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luajit
DISTVERSION=	2.0.2
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/
DISTNAME=	LuaJIT-${DISTVERSION}

#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	v${PORTVERSION}_hotfix1.patch
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	osa@FreeBSD.org
COMMENT=	A Just-In-Time Compiler for Lua

WRKSRC=		${WRKDIR}/LuaJIT-${DISTVERSION}
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_SUB+=	VERSION=${DISTVERSION}

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		luajit.1
.endif

post-install:
	${LN} -sf ${PREFIX}/bin/${PORTNAME}-${DISTVERSION} \
		${PREFIX}/bin/${PORTNAME}
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/etc/luajit.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
