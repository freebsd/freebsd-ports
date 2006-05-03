# New ports collection makefile for:   lua50-filename
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	lua50-filename
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://cvs.bsdinstaller.org/cgi-bin/cvsweb.cgi/installer/src/lib/lua/filename/
DISTFILES=	filename.lua?rev=${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Filename-manipulating functions for Lua 5.0.x

RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${PREFIX}/share/lua/5.0/${DISTFILES:C/\?.*$//}

.include <bsd.port.mk>
