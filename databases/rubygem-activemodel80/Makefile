PORTNAME=	activemodel
PORTVERSION=	8.0.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks like Active Record
WWW=		https://github.com/rails/rails/tree/main/activemodel \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
