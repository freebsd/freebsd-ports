# $FreeBSD$

PORTNAME=	libzim
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Reference implementation of the ZIM specification

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libxapian.so:databases/xapian-core

USES=		meson pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	openzim

.include <bsd.port.mk>
