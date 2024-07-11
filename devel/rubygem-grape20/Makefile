PORTNAME=	grape
PORTVERSION=	2.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions
WWW=		https://www.ruby-grape.org/ \
		https://github.com/ruby-grape/grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=5:devel/rubygem-activesupport70 \
		rubygem-builder>=0:devel/rubygem-builder \
		rubygem-dry-types>=1.1:devel/rubygem-dry-types \
		rubygem-mustermann-grape10>=1.0.0<1.1:devel/rubygem-mustermann-grape10 \
		rubygem-rack>=1.3.0,3:www/rubygem-rack \
		rubygem-rack-accept>=0:www/rubygem-rack-accept

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	ruby-grape

.include <bsd.port.mk>
