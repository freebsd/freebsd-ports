# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	wordgrinder
PORTVERSION=	0.3.3
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	vmagerya@gmail.com
COMMENT=	A simple Unicode-aware console-based word processor

LICENSE=	MIT

RUN_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem

USE_LUA=	5.1+

USE_BZIP2=	yes

MAN1=		wordgrinder.1

PLIST_DIRS=	share/doc/wordgrinder
PLIST_FILES=	bin/wordgrinder share/doc/wordgrinder/README.wg

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,^PREFIX =.*$$,PREFIX = "${PREFIX}",' \
		-e 's,/usr/include/lua5.1,${LUA_INCDIR},' \
		-e 's,command = "lua ,command = "${LUA_CMD} ,' \
		-e '/curses_exe =/s,$$,\
		CLINKFLAGS = {PARENT\, "-L${LUA_LIBDIR}"}\,,' \
		-e 's,lua5.1,lua,' \
		-e 's,install -D,install,' \
		${WRKSRC}/pmfile
	${REINPLACE_CMD} 's,^LUACOMPILER =.*$$,LUACOMPILER = "${LUAC_CMD}",' \
		${WRKSRC}/tools/lua.pm
	${REINPLACE_CMD} "/CCOMPILER = /s,gcc,cc ," ${WRKSRC}/tools/c.pm
	${REINPLACE_CMD} "/CC=/s,gcc,cc ," ${WRKSRC}/pm

do-build:
	(cd ${WRKSRC}; ./pm)

do-install:
	${MKDIR} ${PREFIX}/bin ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/wordgrinder
	(cd ${WRKSRC}; ./pm install)
	${STRIP_CMD} ${PREFIX}/bin/wordgrinder

.include <bsd.port.mk>
