# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	libtermkey
PORTVERSION=	0.18
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/libtermkey/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy processing of keyboard entry from terminal-based programs

LICENSE=	MIT

USES=		gmake libtool:build ncurses pkgconfig
LIB_DEPENDS=	libunibilium.so:devel/unibilium
USE_LDCONFIG=	yes
MAKE_ARGS=	MANDIR=${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/Makefile

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtermkey.so.1.12.0

.include <bsd.port.mk>
