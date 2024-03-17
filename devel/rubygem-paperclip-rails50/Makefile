PORTNAME=	paperclip
PORTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord
WWW=		https://github.com/thoughtbot/paperclip

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream repo archived Jul 13, 2023. Upstream recommends using Rails' own ActiveStorage.
EXPIRATION_DATE=2024-04-30

RUN_DEPENDS=	rubygem-activemodel50>0:databases/rubygem-activemodel50 \
		rubygem-activesupport50>=0:devel/rubygem-activesupport50 \
		rubygem-mimemagic>=0.3.0:misc/rubygem-mimemagic \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-terrapin>=0.6.0:devel/rubygem-terrapin

NO_ARCH=	yes
USES=		cpe gem magick:7,nox11,run
CPE_VENDOR=	thoughtbot

.include <bsd.port.mk>
