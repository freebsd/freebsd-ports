PORTNAME=	ruby-bsdconv
PORTVERSION=	11.3.1
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	buganini@gmail.com
COMMENT=	Ruby wrapper for bsdconv
WWW=		https://github.com/buganini/ruby-bsdconv

LICENSE=	ISCL

LIB_DEPENDS=	libbsdconv.so:converters/bsdconv

CONFIGURE_ARGS=	--with-bsdconv-dir=${LOCALBASE}
USES=		gem

.include <bsd.port.mk>
