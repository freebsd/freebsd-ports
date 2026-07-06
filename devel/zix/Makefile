PORTNAME=	zix
DISTVERSION=	0.8.2
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight C library of portability wrappers and data structures
WWW=		https://drobilla.net/category/zix/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc:devel/glib20

USES=		meson pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=disabled \
		-Dtests=disabled

PLIST_SUB=	VERSION=${DISTVERSION}

do-test:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} -Dtests=enabled && \
	cd ${BUILD_WRKSRC} && \
		${DO_MAKE_BUILD} test

.include <bsd.port.mk>
