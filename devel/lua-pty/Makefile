# New ports collection makefile for:   lua50-pty
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	lua50-pty
PORTVERSION=	1.25
CATEGORIES=	devel
MASTER_SITES=	http://cvs.bsdinstaller.org/cgi-bin/cvsweb.cgi/installer/src/lib/lua/pty/
DISTFILES=	pty.lua?rev=1.2 pty.c?rev=1.25

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Pty (pseudo-terminal) bindings for Lua 5.0.x

BUILD_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:extract
RUN_DEPENDS=	${LOCALBASE}/include/lua.h:${PORTSDIR}/lang/lua50 \
		${LOCALBASE}/share/lua/5.0/compat-5.1.lua:${PORTSDIR}/devel/lua50-compat51

LIBDIR=		${PREFIX}/lib/lua/5.0
COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && make -V WRKSRC)`

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	@${CP} ${DISTDIR}/${file} ${WRKSRC}/${file:C/\?.*$//}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e "s|%%COMPATDIR%%|${COMPAT_SRC}|" ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${LIBDIR}
	${MKDIR} ${PREFIX}/share/lua/5.0
	${INSTALL_DATA} ${WRKSRC}/pty.lua ${PREFIX}/share/lua/5.0

.include <bsd.port.mk>
