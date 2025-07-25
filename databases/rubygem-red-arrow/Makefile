PORTNAME=	red-arrow
PORTVERSION=	20.0.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby bindings of Apache Arrow
WWW=		https://arrow.apache.org/ \
		https://github.com/apache/arrow/tree/main/ruby/red-arrow

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	arrow-glib>=${PORTVERSION:R}:databases/arrow-glib
LIB_DEPENDS=	libarrow.so:databases/arrow \
		libarrow-glib.so:databases/arrow-glib
RUN_DEPENDS=	rubygem-bigdecimal>=3.1.0:math/rubygem-bigdecimal \
		rubygem-csv>=0:devel/rubygem-csv \
		rubygem-extpp>=0.1.1:devel/rubygem-extpp \
		rubygem-gio2>=4.2.3:devel/rubygem-gio2 \
		rubygem-pkg-config>=0:devel/rubygem-pkg-config \

USES=		gem

.include <bsd.port.mk>
