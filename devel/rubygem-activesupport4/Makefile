# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activesupport
PORTVERSION=	4.2.7.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Utility classes and extension that are required by Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-json1>=1.7.7:devel/rubygem-json1 \
		rubygem-minitest>=5.1:devel/rubygem-minitest \
		rubygem-thread_safe>=0.3.4:devel/rubygem-thread_safe \
		rubygem-tzinfo>=1.1:devel/rubygem-tzinfo

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
