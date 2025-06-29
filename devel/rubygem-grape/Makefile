PORTNAME=	grape
PORTVERSION=	2.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions
WWW=		https://www.ruby-grape.org/ \
		https://github.com/ruby-grape/grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport80>=6.1:devel/rubygem-activesupport80 \
		rubygem-dry-types>=1.1:devel/rubygem-dry-types \
		rubygem-mustermann-grape>=1.1.0<1.2:devel/rubygem-mustermann-grape \
		rubygem-rack>=2,3:www/rubygem-rack \
		rubygem-virtus>=1.0.0:devel/rubygem-virtus \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	ruby-grape

.include <bsd.port.mk>
