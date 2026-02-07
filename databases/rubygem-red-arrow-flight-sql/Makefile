PORTNAME=	red-arrow-flight-sql
PORTVERSION=	21.0.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby bindings of Apache Arrow Flight SQL
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/main/ruby/red-arrow-flight-sql

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
RUN_DEPENDS=	rubygem-red-arrow-flight>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-red-arrow-flight

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
