# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	libzip
PORTVERSION=	1.5.1
CATEGORIES=	archivers devel
MASTER_SITES=	https://libzip.org/download/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C library for reading, creating, and modifying ZIP archives

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CPE_VENDOR=	nih

USES=		cmake cpe perl5 ssl tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	test
TEST_TARGET=	test

CMAKE_OFF=	ENABLE_COMMONCRYPTO ENABLE_GNUTLS

.include <bsd.port.mk>
