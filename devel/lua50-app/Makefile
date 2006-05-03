# New ports collection makefile for:   lua50-app
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	app
PORTVERSION=	1.70
CATEGORIES=	devel
MASTER_SITES=	http://cvs.bsdinstaller.org/cgi-bin/cvsweb.cgi/installer/src/lib/lua/app/
PKGNAMEPREFIX=	lua50-
DISTFILES=	app.lua?rev=${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	App framework for Lua 5.0.x

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50
RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${LOCALBASE}/share/lua/5.0/posix.lua:${PORTSDIR}/devel/lua50-posix \
		${LOCALBASE}/share/lua/5.0/filename.lua:${PORTSDIR}/devel/lua50-filename \
		${LOCALBASE}/share/lua/5.0/pty.lua:${PORTSDIR}/devel/lua50-pty

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${PREFIX}/share/lua/5.0/${DISTFILES:C/\?.*$//}

.include <bsd.port.mk>
