PORTNAME=	validates_timeliness
PORTVERSION=	7.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	7

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add validation methods to ActiveModel for validating dates and times
WWW=		https://github.com/adzap/validates_timeliness

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel72>=7.0.0<8:databases/rubygem-activemodel72 \
		rubygem-timeliness>=0.3.10<1:devel/rubygem-timeliness

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.

.include <bsd.port.mk>
