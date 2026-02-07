PORTNAME=	grape
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions
WWW=		https://www.ruby-grape.org/ \
		https://github.com/ruby-grape/grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=5:devel/rubygem-activesupport-gitlab \
		rubygem-builder>=0:devel/rubygem-builder \
		rubygem-dry-types-gitlab>=1.1:devel/rubygem-dry-types-gitlab \
		rubygem-mustermann-grape10>=1.0.0<1.1:devel/rubygem-mustermann-grape10 \
		rubygem-rack>=1.3.0,3:www/rubygem-rack \
		rubygem-rack-accept>=0:www/rubygem-rack-accept

USES=		cpe gem

CPE_VENDOR=	ruby-grape

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.0\.

.include <bsd.port.mk>
