# Created by: Ryan Steinmetz <zi@FreeBSD.org>

PORTNAME=	paperclip
PORTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Easy upload management for ActiveRecord

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use ActiveStorage or a fork kt-paperclip
EXPIRATION_DATE=2021-07-25

RUN_DEPENDS=	rubygem-activemodel4>=4.2.0:databases/rubygem-activemodel4 \
		rubygem-activesupport4>=4.2.0:devel/rubygem-activesupport4 \
		rubygem-mimemagic>=0.3<1:misc/rubygem-mimemagic \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-terrapin>=0.6.0<0.7:devel/rubygem-terrapin

USE_RUBY=	yes
USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
