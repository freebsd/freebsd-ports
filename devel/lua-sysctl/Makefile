# New ports collection makefile for:	lua-sysctl
# Date created:		2009-05-08
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lua-sysctl
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	http://files.kaworu.ch/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A small sysctl(3) interface for lua

USE_LUA=	yes
PLIST_FILES=	lib/lua-sysctl.so

post-patch:
	@${REINPLACE_CMD} -E '/^(C|LD)FLAGS/ s/=/+=/g' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/sysctl/core.so ${PREFIX}/lib/lua-sysctl.so

.include <bsd.port.mk>
