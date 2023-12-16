PORTNAME=	activesupport
PORTVERSION=	7.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit of support libraries and Ruby core extensions extracted from the Rails framework
WWW=		https://github.com/rails/rails/tree/main/activesupport \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0.2<2:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.2.5:net/rubygem-connection_pool \
		rubygem-drb>=0:devel/rubygem-drb \
		rubygem-i18n>=1.6,2<2,2:devel/rubygem-i18n \
		rubygem-minitest>=5.1:devel/rubygem-minitest \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-tzinfo>=2.0<3:devel/rubygem-tzinfo

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	activesupport_project

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
