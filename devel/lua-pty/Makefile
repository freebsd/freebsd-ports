# New ports collection makefile for:   lua50-pty
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	pty
PORTVERSION=	1.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= philip
PKGNAMEPREFIX=	lua50-
DISTFILES=	pty.lua?rev=1.2 pty.c?rev=1.25

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Pty (pseudo-terminal) bindings for Lua 5.0.x

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:extract
RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${LOCALBASE}/share/lua/5.0/compat-5.1.lua:${PORTSDIR}/devel/lua50-compat51

COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && make -V WRKSRC)`

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	@${CP} ${DISTDIR}/${file} ${WRKSRC}/${file:C/\?.*$//}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e "s|%%COMPATDIR%%|${COMPAT_SRC}|" ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/lib/lua/5.0
	${INSTALL_PROGRAM} ${WRKSRC}/lpty.so ${PREFIX}/lib/lua/5.0
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/pty.lua ${PREFIX}/share/lua/5.0

.include <bsd.port.mk>
