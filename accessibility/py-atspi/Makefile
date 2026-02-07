PORTNAME=	atspi
DISTVERSION=	2.46.1
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

CONFLICTS=	at-spi-1.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pkgconfig python tar:xz
USE_PYTHON=	flavors py3kplist
USE_GNOME=	intlhack pygobject3
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
