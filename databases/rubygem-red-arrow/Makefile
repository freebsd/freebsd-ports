PORTNAME=	red-arrow
PORTVERSION=	8.0.0
PORTREVISION=	2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby bindings of Apache Arrow
WWW=		https://arrow.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libarrow-glib.so:databases/arrow-glib
RUN_DEPENDS=	rubygem-bigdecimal>=2.0.3:math/rubygem-bigdecimal \
		rubygem-extpp>=0.0.7:devel/rubygem-extpp \
		rubygem-gio2>=3.5.0:devel/rubygem-gio2 \
		rubygem-native-package-installer>=0:devel/rubygem-native-package-installer \
		rubygem-pkg-config>=0:devel/rubygem-pkg-config \

USES=		gem localbase

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
