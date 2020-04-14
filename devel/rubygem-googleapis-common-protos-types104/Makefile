# $FreeBSD$

PORTNAME=	googleapis-common-protos-types
PORTVERSION=	1.0.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	104

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common protocol buffer types used by Google APIs

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-google-protobuf38>=3.0<4:devel/rubygem-google-protobuf38

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# Workaround for gitaly/gitlab-ce dependency resolving of google-protobuf
# googleapis-common-protos-types 1.0.5 requires google-protobuf ~> 3.11
# while gitaly/gitlab-ce requires google-protobuf ~> 3.8.0
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
