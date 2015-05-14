# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/py3-atspi/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	atspi
PORTVERSION=	2.12.0
PORTREVISION=	2
CATEGORIES=	accessibility x11-toolkits python
MASTER_SITES=	GNOME/sources/pyatspi/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyatspi-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python3 API for the D-BUS based SPI framework

RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core

CONFLICTS=	at-spi-1.[0-9]*

USES=		gettext gmake pathfix pkgconfig python:3 tar:xz
USE_GNOME=	intlhack py3gobject3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB+=	PYVER=${PYTHON_VER:S/.//}

.include <bsd.port.mk>
