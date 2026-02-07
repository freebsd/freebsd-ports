PORTNAME=	activemodel
PORTVERSION=	4.2.11.3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/activemodel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=${PORTVERSION}:devel/rubygem-activesupport4 \
		rubygem-builder>=3.1<4:devel/rubygem-builder

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.2\.

.include <bsd.port.mk>
