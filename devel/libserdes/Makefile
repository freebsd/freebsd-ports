PORTNAME=	libserdes
PORTVERSION=	6.0.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sergey@akhmatov.ru
COMMENT=	Schema-based serializer/deserializer with support for Avro
WWW=		https://github.com/confluentinc/libserdes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libavro.so:devel/avro-c \
		libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		librdkafka++.so:net/librdkafka

USES=		gmake localbase:ldflags perl5

USE_GITHUB=	yes
GH_ACCOUNT=	confluentinc

USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libserdes.so

.include <bsd.port.mk>
