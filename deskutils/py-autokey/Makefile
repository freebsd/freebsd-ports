# $FreeBSD$

PORTNAME=	autokey
DISTVERSIONPREFIX=	v
DISTVERSION=	0.95.9
CATEGORIES=	deskutils python
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

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils concurrent
USE_GITHUB=	yes

INSTALLS_ICONS=	yes

NO_ARCH=	yes

OPTIONS_MULTI=	GUI
OPTIONS_MULTI_GUI=	GTK3 QT5
OPTIONS_DEFAULT=	GTK3
OPTIONS_SUB=	yes

GTK3_RUN_DEPENDS=	libappindicator>0:devel/libappindicator
GTK3_USES=	gnome
GTK3_USE=	GNOME=gtk30,gtksourceview3,pygobject3

QT5_USES=	pyqt:5
QT5_USE=	PYQT=dbus,qscintilla2,sip,svg,xml

post-patch:
	@${REINPLACE_CMD} 's|share/man|man|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} "/install_requires=/s|'dbus-python', ||g" ${WRKSRC}/setup.py

# setup.py installs both gtk and qt files no matter what, need to clean that up.
post-install-GTK3-off:
	@${RM} ${STAGEDIR}${PREFIX}/share/applications/autokey-gtk.desktop
	@${RM} ${STAGEDIR}${PREFIX}/bin/autokey-gtk
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/autokey-gtk.1
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}${PORTNAME}/gtkui

post-install-QT5-off:
	@${RM} ${STAGEDIR}${PREFIX}/share/applications/autokey-qt.desktop
	@${RM} ${STAGEDIR}${PREFIX}/bin/autokey-qt
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/autokey-qt.1
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}${PORTNAME}/gtkui

.include <bsd.port.mk>
