# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	posix
PORTVERSION=	34.0.1
DISTVERSIONPREFIX=	release-v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX layer for Lua

LICENSE=	MIT

USES=		lua shebangfix
SHEBANG_FILES=	${WRKSRC}/build-aux/luke

USE_GITHUB=	yes
GH_PROJECT=	luaposix
GH_ACCOUNT=	luaposix

do-build:
	cd ${WRKSRC}; ${WRKSRC}/build-aux/luke \
		version="${PORTVERSION}" \
		PREFIX="${PREFIX}" \
		LUA="${LOCALBASE}/bin/lua${LUA_VER_STR}" \
		LUA_INCDIR="${LUA_INCDIR}" \
		CFLAGS="${CFLAGS}"

do-install:
	cd ${WRKSRC}; ${WRKSRC}/build-aux/luke install \
		INST_LIBDIR="${STAGEDIR}${LUA_MODLIBDIR}" \
		INST_LUADIR="${STAGEDIR}${LUA_MODSHAREDIR}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/ctype.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/dirent.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/errno.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/fcntl.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/fnmatch.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/glob.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/grp.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/libgen.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/poll.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/pwd.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/poll.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/pwd.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sched.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/signal.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/stdio.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/stdlib.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/msg.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/resource.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/socket.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/stat.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/statvfs.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/time.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/times.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/utsname.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/sys/wait.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/syslog.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/termio.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/time.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/unistd.so
	${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/posix/utime.so

.include <bsd.port.mk>
