PORTNAME=	validates_timeliness
PORTVERSION=	6.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add validation methods to ActiveModel for validating dates and times
WWW=		https://github.com/adzap/validates_timeliness

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel61>=6.0.0<7:databases/rubygem-activemodel61 \
		rubygem-timeliness>=0.3.10<1:devel/rubygem-timeliness

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
