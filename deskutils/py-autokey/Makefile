# $FreeBSD$

PORTNAME=	autokey
DISTVERSION=	0.95.4
CATEGORIES=	deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daniel@shafer.cc
COMMENT=	Desktop automation utility for FreeBSD and X11

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlib>0:x11-toolkits/py-xlib@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinotify>0:devel/py-pyinotify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlib>0:x11-toolkits/py-xlib@${PY_FLAVOR}

USES=		python:3.5+ shebangfix
USE_PYTHON=	distutils

NO_ARCH=	yes

OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	GTK3 QT5
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=	yes

GTK3_RUN_DEPENDS=	libappindicator>0:devel/libappindicator
GTK3_USES=	gnome
GTK3_USE=	GNOME=gtk30,gtksourceview3,pygobject3

QT5_USES=	pyqt:5 qt:5
QT5_USE=	PYQT=qscintilla2,sip,svg,xml

post-patch:
	${REINPLACE_CMD} 's|share/man|man|g' ${WRKSRC}/setup.py
	# Remove dbus-python from reqs as its the wrong dep name, devs will fix next release.
	${REINPLACE_CMD} "/install_requires=/s|'dbus-python', ||g" ${WRKSRC}/setup.py

# setup.py installs both gtk and qt files no matter what, need to clean that up.
post-install-GTK3-off:
	${RM} ${STAGEDIR}${PREFIX}/share/applications/autokey-gtk.desktop
	${RM} ${STAGEDIR}${PREFIX}/bin/autokey-gtk
	${RM} ${STAGEDIR}${PREFIX}/man/man1/autokey-gtk.1
post-install-QT5-off:
	${RM} ${STAGEDIR}${PREFIX}/share/applications/autokey-qt.desktop
	${RM} ${STAGEDIR}${PREFIX}/bin/autokey-qt
	${RM} ${STAGEDIR}${PREFIX}/man/man1/autokey-qt.1

.include <bsd.port.mk>
