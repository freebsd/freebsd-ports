PORTNAME=	grape_logging
PORTVERSION=	3.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Request logging for Grape
WWW=		https://github.com/aserafin/grape_logging

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-grape-gitlab>=2.4.0:devel/rubygem-grape-gitlab \
		rubygem-rack-gitlab>=0:www/rubygem-rack-gitlab \
		rubygem-zeitwerk-gitlab>=0:devel/rubygem-zeitwerk-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
