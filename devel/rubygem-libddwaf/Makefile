PORTNAME=	libddwaf
PORTVERSION=	1.24.1.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	WAF implementation in C++, exposed to Ruby
WWW=		https://github.com/DataDog/libddwaf-rb

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.Apache
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD3

LIB_DEPENDS=	libddwaf.so:devel/libddwaf
RUN_DEPENDS=	rubygem-ffi>=1.0<2:devel/rubygem-ffi

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
