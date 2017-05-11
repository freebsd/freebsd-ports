# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jbuilder
PORTVERSION=	2.6.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Create JSON structures via a Builder-style DSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport5>0:devel/rubygem-activesupport5 \
		rubygem-multi_json>=1.2:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
