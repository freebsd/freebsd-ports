# Created by: Anton tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	libvterm
PORTVERSION=	git20150828
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of a VT220/xterm/ECMA-48 terminal emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	neovim
GH_TAGNAME=	342e61e

USES=		gmake libtool:build perl5
USE_LDCONFIG=	yes

pre-build:
	${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/unterm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-ctrl
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vterm-dump
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvterm.so

.include <bsd.port.mk>
