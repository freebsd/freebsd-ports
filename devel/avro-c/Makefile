PORTNAME=	avro
PORTVERSION=	1.12.1
CATEGORIES=	devel
MASTER_SITES=	APACHE/avro/avro-${PORTVERSION}/c
PKGNAMESUFFIX=	-c
DISTNAME=	avro-c-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for Apache Avro
WWW=		https://avro.apache.org/ \
		https://github.com/apache/avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libsnappy.so:archivers/snappy

USES=		cmake cpe pkgconfig shebangfix

USE_LDCONFIG=	yes

CPE_VENDOR=	apache

SHEBANG_FILES=	version.sh
bash_CMD=	/bin/sh

.include <bsd.port.mk>
