PORTNAME=	activemodel
PORTVERSION=	5.2.8.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks
WWW=		https://rubyonrails.org/ \
		https://github.com/rails/rails/tree/main/activemodel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=${PORTVERSION}:devel/rubygem-activesupport52

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^5\.2\.

.include <bsd.port.mk>
