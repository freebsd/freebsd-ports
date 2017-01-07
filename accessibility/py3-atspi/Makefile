# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atspi
PORTVERSION=	2.18.0
CATEGORIES=	accessibility x11-toolkits python
MASTER_SITES=	GNOME/sources/pyatspi/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyatspi-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python3 API for the D-BUS based SPI framework

RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:accessibility/at-spi2-core

CONFLICTS=	at-spi-1.[0-9]*
PORTSCOUT=	limitw:1,even

NO_ARCH=	yes
USES=		gettext gmake gnome pathfix pkgconfig python:3 tar:xz
USE_GNOME=	intlhack py3gobject3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
