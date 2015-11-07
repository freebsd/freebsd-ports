# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	wordgrinder
PORTVERSION=	0.6
CATEGORIES=	editors

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Simple Unicode-aware console and X11-based word processor

RUN_DEPENDS=	${LUA_MODLIBDIR}/lfs.so:${PORTSDIR}/devel/luafilesystem

USE_GITHUB=	yes
GH_ACCOUNT=	davidgiven

USES=		gmake lua:52

PLIST_FILES=	bin/wordgrinder \
		share/doc/wordgrinder/README.wg \
		man/man1/wordgrinder.1.gz

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_DESC=	Support running in an X window in addition to console
X11_PLIST_FILES=bin/xwordgrinder
X11_USE=	xorg=x11,xft
X11_USES=	pkgconfig
X11_ALL_TARGET_OFF=unix

.include <bsd.port.options.mk>

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
		-e '/install /s|share/man/man1|man/man1|' \
		-e '/NCURSES_CFLAGS :=/s|=.*|=|' \
		-e '/NCURSES_LIB :=/s|=.*|= -lncursesw|' \
		-e '/X11_CFLAGS :=/s|=.*|= $$(shell pkg-config --cflags x11 xft)|' \
		-e '/X11_LIB :=/s|=.*|= $$(shell pkg-config --libs x11 xft)|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e '/#include <Xft/s|<|<X11/|' \
		${WRKSRC}/src/c/arch/unix/x11/x11.h
.if ! ${PORT_OPTIONS:MX11}
	# This is not strictly speaking required, but it cuts
	# down on some unnecessary work and error messages.
	${REINPLACE_CMD} \
		-e '/$$(eval $$(build-wordgrinder-x11))/d' \
		${WRKSRC}/Makefile
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wordgrinder
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xwordgrinder ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
