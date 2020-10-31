# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	flamethrower
DISTVERSIONPREFIX=v
PORTVERSION=	0.11.0
CATEGORIES=	dns

MAINTAINER=	pcarboni@gmail.com
COMMENT=	DNS performance and functional testing utility

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libnghttp2.so:www/libnghttp2 \
		libuv.so:devel/libuv \
		libldns.so:dns/ldns

USES=		cmake compiler:c++17-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	DNS-OARC

INSTALL_TARGET=
TEST_TARGET=	${BUILD_WRKSRC}/tests
CMAKE_ON=	DOH_ENABLE
PLIST_FILES=	bin/flame

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/flame ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
