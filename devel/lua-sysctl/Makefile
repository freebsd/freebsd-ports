# New ports collection makefile for:	lua-sysctl
# Date created:		2009-05-08
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lua-sysctl
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://files.kaworu.ch/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A small sysctl(3) interface for lua

USE_LUA=	yes
PLIST_FILES=	%%LUA_MODSHAREDIR%%/sysctl.lua \
		%%LUA_MODLIBDIR%%/sysctl/core.so
PLIST_DIRS=	%%LUA_MODLIBDIR%%/sysctl

post-patch:
	@${REINPLACE_CMD} -E '/^(C|LD)FLAGS/ s/=/+=/g' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${LUA_MODLIBDIR}/sysctl
	${INSTALL_SCRIPT} ${WRKSRC}/sysctl.lua ${LUA_MODSHAREDIR}/sysctl.lua
	${INSTALL_SCRIPT} ${WRKSRC}/sysctl/core.so ${LUA_MODLIBDIR}/sysctl/core.so

.include <bsd.port.mk>
