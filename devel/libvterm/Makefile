# Created by: Anton tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	libvterm
PORTVERSION=	git20160104
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of a VT220/xterm/ECMA-48 terminal emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	neovim
GH_TAGNAME=	a9c7c6f

USES=		gmake libtool:build pathfix perl5
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
MAKE_ARGS=	PREFIX=${PREFIX}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/unterm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-ctrl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-dump
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvterm.so

.include <bsd.port.mk>
