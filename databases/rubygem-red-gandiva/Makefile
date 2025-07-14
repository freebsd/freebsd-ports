PORTNAME=	red-gandiva
PORTVERSION=	20.0.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby bindings of Gandiva
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/master/ruby/red-gandiva

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-red-arrow>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-red-arrow

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
