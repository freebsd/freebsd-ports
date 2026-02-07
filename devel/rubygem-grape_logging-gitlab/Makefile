PORTNAME=	grape_logging
PORTVERSION=	1.8.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Request logging for Grape
WWW=		https://github.com/aserafin/grape_logging

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-grape20>=0:devel/rubygem-grape20 \
		rubygem-rack>=0,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
