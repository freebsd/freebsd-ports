PORTNAME=	libtickit
PORTVERSION=	0.4.4
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/libtickit/trunk/v${PORTVERSION:R}/+download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Terminal Interface Construction Kit
WWW=		https://www.leonerd.org.uk/code/libtickit/ \
		https://launchpad.net/libtickit \
		https://github.com/leonerd/libtickit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtermkey.so:devel/libtermkey

USES=		compiler:c11 gmake libtool:build ncurses pathfix pkgconfig

MAKE_ARGS=	MANDIR=${PREFIX}/share/man
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtickit.so

.include <bsd.port.mk>
