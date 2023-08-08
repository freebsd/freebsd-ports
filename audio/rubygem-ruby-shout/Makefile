PORTNAME=	ruby-shout
PORTVERSION=	2.2.2
CATEGORIES=	audio rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding to the libshout library
WWW=		https://github.com/niko/ruby-shout

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libshout.so:audio/libshout

CONFIGURE_ARGS=	--with-opt-include="${LOCALBASE}/include"
USES=		gem

.include <bsd.port.mk>
