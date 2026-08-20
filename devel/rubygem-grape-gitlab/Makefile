PORTNAME=	grape
PORTVERSION=	2.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions
WWW=		https://www.ruby-grape.org/ \
		https://github.com/ruby-grape/grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport-gitlab>=6.1:devel/rubygem-activesupport-gitlab \
		rubygem-dry-types-gitlab>=1.1:devel/rubygem-dry-types-gitlab \
		rubygem-mustermann-grape>=1.1.0<1.2:devel/rubygem-mustermann-grape \
		rubygem-rack>=2.0.0,3:www/rubygem-rack \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

USES=		cpe gem

CPE_VENDOR=	ruby-grape

NO_ARCH=	yes

.include <bsd.port.mk>
