PORTNAME=	validates_timeliness
PORTVERSION=	8.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Add validation methods to ActiveModel for validating dates and times
WWW=		https://github.com/adzap/validates_timeliness

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel80>=8.0.0<9:databases/rubygem-activemodel80 \
		rubygem-timeliness>=0.3.10<1:devel/rubygem-timeliness

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
