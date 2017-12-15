# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atspi
PORTVERSION=	2.24.0
CATEGORIES=	accessibility x11-toolkits python
MASTER_SITES=	GNOME/sources/pyatspi/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyatspi-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python API for the D-BUS based SPI framework

LICENSE=	LGPL20

RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:accessibility/at-spi2-core

CONFLICTS=	at-spi-1.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig python tar:xz
USE_PYTHON=	flavors
.if ${FLAVOR:Upy27:Mpy2*} 
USE_GNOME=	intlhack pygobject3
.else
USE_GNOME=	intlhack py3gobject3
.endif
py34_PLIST=	${.CURDIR}/pkg-plist-py3
py35_PLIST=	${.CURDIR}/pkg-plist-py3
py36_PLIST=	${.CURDIR}/pkg-plist-py3
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
