# $FreeBSD$

PORTNAME=	cyoi
PORTVERSION=	0.11.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library to prompt for infrastructure and login credentials

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog>=0:devel/rubygem-fog \
		rubygem-highline1>=1.6<2:devel/rubygem-highline1 \
		rubygem-readwritesettings>=3.0:devel/rubygem-readwritesettings

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/cyoi

.include <bsd.port.mk>
