PORTNAME=	google-protobuf
PORTVERSION=	4.36.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby extension to Google Protocol Buffers
WWW=		https://protobuf.dev/ \
		https://github.com/protocolbuffers/protobuf \
		https://github.com/protocolbuffers/protobuf/tree/main/ruby

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-bigdecimal-gitlab>=0:math/rubygem-bigdecimal-gitlab \
		rubygem-rake>=13.3<14:devel/rubygem-rake

USES=		cpe gem shebangfix

CPE_VENDOR=	google
CPE_PRODUCT=	protobuf

SHEBANG_GLOB=	*.rb

.include <bsd.port.mk>
