PORTNAME=	libevdev
PORTVERSION=	1.13.2
CATEGORIES=	devel
MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Linux Event Device library
WWW=		https://www.freedesktop.org/wiki/Software/libevdev/

LICENSE=	MIT # without linux/*.h
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig python:build shebangfix tar:xz
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocumentation=disabled -Dtests=disabled
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
