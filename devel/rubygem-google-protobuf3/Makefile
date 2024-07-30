PORTNAME=	google-protobuf
PORTVERSION=	3.25.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby extension to Google Protocol Buffers
WWW=		https://protobuf.dev/ \
		https://github.com/protocolbuffers/protobuf \
		https://github.com/protocolbuffers/protobuf/tree/main/ruby

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake

USES=		gem shebangfix

PORTSCOUT=	limit:^3\.

SHEBANG_GLOB=	*.rb

.include <bsd.port.mk>
