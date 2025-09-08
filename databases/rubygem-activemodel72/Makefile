PORTNAME=	activemodel
PORTVERSION=	7.2.2.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for building modeling frameworks like Active Record
WWW=		https://github.com/rails/rails/tree/main/activemodel \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport72

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include <bsd.port.mk>
