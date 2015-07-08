# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	libtermkey
PORTVERSION=	0.17
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/libtermkey/

MAINTAINER=	antont@inbox.lv
COMMENT=	Easy processing of keyboard entry from terminal-based programs

LICENSE=	MIT

USES=		gmake libtool:build
LIB_DEPENDS=	libunibilium.so:${PORTSDIR}/devel/unibilium
USE_LDCONFIG=	yes

pre-build:
	${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/Makefile

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtermkey.so.1.11.0

.include <bsd.port.mk>
