PORTNAME=	activesupport
PORTVERSION=	7.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit of support libraries and Ruby core extensions extracted from the Rails framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.2<2:devel/rubygem-concurrent-ruby \
		rubygem-i18n>=1.6,2<2,2:devel/rubygem-i18n \
		rubygem-minitest>=5.1:devel/rubygem-minitest \
		rubygem-tzinfo>=2.0<3:devel/rubygem-tzinfo

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	activesupport_project

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
