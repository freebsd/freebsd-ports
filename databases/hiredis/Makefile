PORTNAME=	hiredis
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Minimalistic C client library for the Redis database

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	redis

USES=		cpe gmake
USE_LDCONFIG=	yes

CPE_VENDOR=	redislabs

OPTIONS_DEFINE=		OPENSSL
OPTIONS_DEFAULT=	OPENSSL
OPENSSL_MAKE_ARGS=	USE_SSL=1

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\$$(INSTALL_LIBRARY_PATH)/\$$(PKGCONF_PATH)|\$$(DESTDIR)\$$(PREFIX)/libdata/\$$(PKGCONF_PATH)|' \
		${WRKSRC}/Makefile

post-build:
	@${STRIP_CMD} ${WRKSRC}/libhiredis.so

do-test:
	cd ${WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
