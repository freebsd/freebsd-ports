# $FreeBSD$

PORTNAME=	libevdev
PORTVERSION=	1.9.1.20200928
CATEGORIES=	devel
#MASTER_SITES=	http://freedesktop.org/software/${PORTNAME}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Linux Event Device library

LICENSE=	MIT # without linux/*.h
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig python:3.5+,build shebangfix
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	6ea230bc72353c54fac628987b87cc1d3b6fd842

MESON_ARGS=	-Ddocumentation=disabled -Dtests=disabled

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
