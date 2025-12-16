PORTNAME=	libtickit
PORTVERSION=	0.4.5
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/libtickit/trunk/v${PORTVERSION:R}/+download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal Interface Construction Kit
WWW=		https://www.leonerd.org.uk/code/libtickit/ \
		https://launchpad.net/libtickit \
		https://github.com/leonerd/libtickit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtermkey.so:devel/libtermkey \
		libunibilium.so:devel/unibilium

USES=		compiler:c11 gmake libtool:build ncurses pkgconfig

USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtickit.so

.include <bsd.port.mk>
