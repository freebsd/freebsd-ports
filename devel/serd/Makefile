PORTNAME=	serd
DISTVERSION=	0.32.2
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	meka@tilda.center
COMMENT=	C library for RDF syntax
WWW=		https://drobilla.net/software/serd.html

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig python:test tar:xz
USE_CSTD=	c99
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=disabled

PLIST_SUB=	VERSION=${PORTVERSION}

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
