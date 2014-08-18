# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/py3-atspi/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	atspi
PORTVERSION=	2.12.0
PORTREVISION=	1
CATEGORIES=	accessibility x11-toolkits python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pyatspi/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyatspi-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python3 API for the D-BUS based SPI framework

RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core

CONFLICTS=	at-spi-1.[0-9]*

USES=		gettext gmake pathfix pkgconfig python:3 tar:xz
USE_GNOME=	gnomehier intlhack py3gobject3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
