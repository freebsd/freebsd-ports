PORTNAME=	re2
PORTVERSION=	2.19.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby bindings to re2
WWW=		https://github.com/mudge/re2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libgmp.so:math/gmp \
		libre2.so:devel/re2
RUN_DEPENDS=	rubygem-mini_portile2>=2.8.7<2.9:devel/rubygem-mini_portile2

USES=		gem
CONFIGURE_ARGS=	--enable-system-libraries

.include <bsd.port.mk>
