PORTNAME=	sord
DISTVERSION=	0.16.14
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight C library for storing RDF data in memory
WWW=		https://drobilla.net/category/sord/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libserd-0.so:devel/serd

USES=		meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
