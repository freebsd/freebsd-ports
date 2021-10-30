# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	paperclip
PORTVERSION=	6.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel50>0:databases/rubygem-activemodel50 \
		rubygem-activesupport50>=0:devel/rubygem-activesupport50 \
		rubygem-mimemagic>=0.3.0:misc/rubygem-mimemagic \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-terrapin>=0.6.0:devel/rubygem-terrapin

NO_ARCH=	yes
USE_RUBY=	yes
USES=		cpe gem magick:7,nox11,run
CPE_VENDOR=	thoughtbot

.include <bsd.port.mk>
