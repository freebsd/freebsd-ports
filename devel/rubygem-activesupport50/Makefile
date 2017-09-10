# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activesupport
PORTVERSION=	5.0.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility classes and extension that are required by Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.2:devel/rubygem-concurrent-ruby \
		rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-minitest>=5.1:devel/rubygem-minitest \
		rubygem-tzinfo>=1.1:devel/rubygem-tzinfo

PORTSCOUT=	limit:^5\.0\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
