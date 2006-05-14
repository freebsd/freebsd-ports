# New ports collection makefile for:   lua50-posix
# Date created:        27 March 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	lua50-posix
PORTVERSION=	5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.0/
DISTFILES=	lposix.tar.gz

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	A POSIX layer for Lua

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50

WRKSRC=		${WRKDIR}/posix

do-install:
	@ ${MKDIR} ${PREFIX}/share/lua/5.0
	@ ${INSTALL_DATA} ${WRKSRC}/posix.lua ${PREFIX}/share/lua/5.0
	@ ${MKDIR} ${PREFIX}/lib/lua/5.0
	@ ${INSTALL_PROGRAM} ${WRKSRC}/lposix.so ${PREFIX}/lib/lua/5.0

.include <bsd.port.mk>
