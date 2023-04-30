PORTNAME=	kt-paperclip
PORTVERSION=	7.1.1
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord
WWW=		https://github.com/kreeti/kt-paperclipp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activemodel61>0:databases/rubygem-activemodel61 \
		rubygem-activesupport61>=0:devel/rubygem-activesupport61 \
		rubygem-marcel>0:devel/rubygem-marcel \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-terrapin>=0.6.0:devel/rubygem-terrapin

NO_ARCH=	yes
USES=		cpe gem magick:7,run
CPE_VENDOR=	thoughtbot

.include <bsd.port.mk>
