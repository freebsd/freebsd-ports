PORTNAME=	activesupport
PORTVERSION=	${RAILS_VERSION}
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Toolkit of support libraries and Ruby core extensions extracted from the Rails framework
WWW=		https://github.com/rails/rails/tree/main/activesupport \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-benchmark>=0.3:benchmarks/rubygem-benchmark \
		rubygem-bigdecimal-gitlab>=0:math/rubygem-bigdecimal-gitlab \
		rubygem-concurrent-ruby>=1.3.1<2:devel/rubygem-concurrent-ruby \
		rubygem-connection_pool>=2.2.5:net/rubygem-connection_pool \
		rubygem-drb>=0:devel/rubygem-drb \
		rubygem-i18n>=1.6,2<2,2:devel/rubygem-i18n \
		rubygem-logger-gitlab>=1.4.2:devel/rubygem-logger-gitlab \
		rubygem-minitest>=5.1:devel/rubygem-minitest \
		rubygem-securerandom>=0.3:security/rubygem-securerandom \
		rubygem-tzinfo>=2.0.5<3:devel/rubygem-tzinfo

USES=		cpe gem

CPE_VENDOR=	activesupport_project

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include "${.CURDIR}/../../www/gitlab/Makefile.common"
.include <bsd.port.mk>
