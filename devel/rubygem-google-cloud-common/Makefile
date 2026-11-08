PORTNAME=	google-cloud-common
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common protocol buffer types used by Google Cloud APIs
WWW=		https://github.com/googleapis/common-protos-ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-googleapis-common-protos-types-gitlab>=1.7<2:devel/rubygem-googleapis-common-protos-types-gitlab \
		rubygem-google-protobuf-gitlab>=3.18<5:devel/rubygem-google-protobuf-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
