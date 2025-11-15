PORTNAME=	lilv
DISTVERSION=	0.26.0
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Make use of LV2 plugins as simple as possible
WWW=		https://drobilla.net/software/lilv

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsndfile.so:audio/libsndfile \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libzix-0.so:devel/zix
RUN_DEPENDS=	lv2>=1.14.0:audio/lv2

USES=		meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=disabled
BINARY_ALIAS=	python3=${PYTHON_CMD}
PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
