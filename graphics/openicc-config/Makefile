PORTNAME=	openicc-config
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color configuration data base management
WWW=		https://github.com/OpenICC/config

LICENSE=	MIT

DEPRECATED=	Abandoned upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

LIB_DEPENDS=	libyajl.so:devel/yajl

USE_GITHUB=	yes
GH_ACCOUNT=	OpenICC
GH_PROJECT=	config
USES=		cmake gettext iconv:build pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
