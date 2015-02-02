# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	wordgrinder
PORTVERSION=	0.5.2
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Simple Unicode-aware console-based word processor

LICENSE=	MIT

RUN_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem

USES=		lua:52 tar:bzip2 gmake

PLIST_FILES=	bin/wordgrinder \
		share/doc/wordgrinder/README.wg \
		man/man1/wordgrinder.1.gz

post-patch:
	${REINPLACE_CMD} \
		-e '/hide = /s/@//' \
		-e '/cc := gcc/s|gcc|${CC}|' \
		-e '/LUA_INCLUDE := /s|= .*|= ${LUA_INCDIR}|' \
		-e '/ldflags := /s|=|= -L${LUA_LIBDIR}|' \
		-e 's|-llua5.2|-llua-${LUA_VER}|' \
		-e 's|$$(hide)lua|$$(hide)${LUA_CMD}|' \
		-e '/PREFIX = /d' \
		-e '/install /s|$$(PRE|$$(DESTDIR)$$(PRE|' \
		-e '/install /s|-D||' \
		-e '/install /s|share/man/man1|man/man1|' \
		${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/wordgrinder

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wordgrinder

.include <bsd.port.mk>
