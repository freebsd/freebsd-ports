# $FreeBSD$

PORTNAME=	syncthing-gtk
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils python

MAINTAINER=	bsd@abinet.ru
COMMENT=	Python based GUI for Syncthing

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing

USES=		python:2
USE_PYTHON=	autoplist distutils
USE_GNOME=	gtk30 pygobject3
INSTALLS_ICONS=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/syncthing-gtk.desktop \
		${WRKSRC}/syncthing_gtk/configuration.py

.include <bsd.port.mk>
