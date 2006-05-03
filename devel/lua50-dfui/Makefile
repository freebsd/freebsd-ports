# New ports collection makefile for:   lua50-dfui
# Date created:        18 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	dfui
PORTVERSION=	0.1.20050901
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	philip
PKGNAMEPREFIX=	lua50-
DISTNAME=	lua-dfui-0.1.20050901

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	DFUI binding for Lua 5.0.x

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:extract
LIB_DEPENDS=	dfui4.4:${PORTSDIR}/devel/libdfui
RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${LOCALBASE}/share/lua/5.0/compat-5.1.lua:${PORTSDIR}/devel/lua50-compat51 \
		${LOCALBASE}/share/lua/5.0/posix.lua:${PORTSDIR}/devel/lua50-posix

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/lua-dfui-${PORTVERSION}

COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && make -V WRKSRC)`
MAKE_ENV=	COMPAT=${COMPAT_SRC}

do-install:
	${MKDIR} ${PREFIX}/lib/lua/5.0
	${INSTALL_PROGRAM} ${WRKSRC}/ldfui.so ${PREFIX}/lib/lua/5.0
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/dfui.lua ${PREFIX}/share/lua/5.0

.include <bsd.port.mk>
