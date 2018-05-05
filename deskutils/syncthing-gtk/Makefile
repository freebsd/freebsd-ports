# $FreeBSD$

PORTNAME=	syncthing-gtk
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3.1
CATEGORIES=	deskutils python

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Python based GUI for Syncthing

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>0:security/py-bcrypt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${FLAVOR} \
		libappindicator>=0:devel/libappindicator \
		syncthing>=0.13:net/syncthing

USES=		python:2.7
USE_PYTHON=	autoplist distutils
USE_GNOME=	gtk30 pygobject3
INSTALLS_ICONS=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	syncthing

OPTIONS_DEFAULT=	NOTIFY
OPTIONS_DEFINE=	NOTIFY

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/syncthing-gtk.desktop \
		${WRKSRC}/syncthing_gtk/configuration.py

.include <bsd.port.mk>
