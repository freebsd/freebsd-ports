PORTNAME=	avro
PORTVERSION=	1.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG \
		APACHE/avro/avro-${PORTVERSION}/ruby

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library for Apache Avro
WWW=		https://avro.apache.org/ \
		https://github.com/apache/avro

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=1.0<2:devel/rubygem-multi_json

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	apache

.include <bsd.port.mk>
