PORTNAME=	libmaa
PORTVERSION=	1.5.1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides a few data structures and helpful functions
WWW=		https://github.com/cheusov/libmaa

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	mk-configure>=0.29.1:devel/mk-configure

CFLAGS+=	-fPIC
MAKE_CMD=	mkcmake
USE_LDCONFIG=	yes

GH_ACCOUNT=	cheusov
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmaa.so

.include <bsd.port.mk>
