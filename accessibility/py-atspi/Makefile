PORTNAME=	atspi
DISTVERSION=	2.58.1
CATEGORIES=	accessibility x11-toolkits python
MASTER_SITES=	GNOME
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyatspi-${DISTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python API for the D-BUS based SPI framework
WWW=		https://gitlab.gnome.org/GNOME/pyatspi2

LICENSE=	LGPL20

RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:accessibility/at-spi2-core

USES=		gnome localbase meson pkgconfig python tar:xz
USE_GNOME=	pygobject3
USE_PYTHON=	flavors py3kplist
BINARY_ALIAS=	python3=${PYTHON_CMD}

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
