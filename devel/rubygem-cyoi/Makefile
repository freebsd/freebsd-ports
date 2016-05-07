# $FreeBSD$

PORTNAME=	cyoi
PORTVERSION=	0.11.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library to prompt for infrastructure and login credentials

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fog>=0:devel/rubygem-fog \
		rubygem-highline>=1.6:devel/rubygem-highline \
		rubygem-readwritesettings>=3.0:devel/rubygem-readwritesettings

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/cyoi

.include <bsd.port.mk>
