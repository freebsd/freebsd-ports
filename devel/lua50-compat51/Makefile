# New ports collection makefile for:   lua50-compat51
# Date created:        14 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	lua50-compat51
PORTVERSION=	${CVER}.${CREV}
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/1410/
DISTNAME=	compat-${CVER}${CREV}.tar.gz

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Lua 5.1 package compatibility layer for Lua 5.0.x

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50

CONFLICTS=	luasocket-2.0

# Update these values when there is a new release
CVER=		5.1
CREV=		r5

WRKSRC=		${WRKDIR}/compat-${CVER}${CREV}
LIBDIR=		${PREFIX}/lib

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/compat-5.1.lua ${PREFIX}/share/lua/5.0

.include <bsd.port.mk>
