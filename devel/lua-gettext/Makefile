# New ports collection makefile for:   lua50-gettext
# Date created:        31 May 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://cvs.bsdinstaller.org/cgi-bin/cvsweb.cgi/installer/src/lib/lua/gettext/
PKGNAMEPREFIX=	lua50-
DISTFILES=	lua_gettext.c?rev=${CVER} gettext.lua?rev=${LVER}

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Gettext ibinding for Lua 5.0.x

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50
RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50

USE_GETTEXT=	yes

LIBDIR=		${PREFIX}/lib/lua/5.0

CVER=		1.15
LVER=		${PORTVERSION}

do-extract:
	${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	${CP} ${DISTDIR}/${file} ${WRKSRC}/${file:C/\?.*$//}
.endfor
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/lib/lua/5.0
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/gettext.lua ${PREFIX}/share/lua/5.0/
	${MKDIR} ${PREFIX}/lib/lua/5.0
	${INSTALL_PROGRAM} ${WRKSRC}/lgettext.so ${PREFIX}/lib/lua/5.0/

.include <bsd.port.mk>
