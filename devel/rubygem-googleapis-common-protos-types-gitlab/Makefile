PORTNAME=	googleapis-common-protos-types
PORTVERSION=	1.20.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common protocol buffer types used by Google APIs
WWW=		https://github.com/googleapis/common-protos-ruby/tree/main/googleapis-common-protos-types \
		https://github.com/googleapis/common-protos-ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf>=3.18<5.0:devel/rubygem-google-protobuf

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.20\.

.include <bsd.port.mk>
