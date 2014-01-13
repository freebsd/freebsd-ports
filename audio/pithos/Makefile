# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	0.3.18
CATEGORIES=	audio
DISTNAME=	${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	pithos	
GH_PROJECT=	pithos
GH_COMMIT=	0770210

MAINTAINER=	john@pcbsd.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_PYTHON=	yes
NO_STAGE=	yes
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	easy_install
USE_GSTREAMER=	good bad python
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}
PYEASYINSTALL_EGG=	pithos-0.3-py2.7.egg

post-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${DATADIR})
	@(cd ${WRKSRC}/pithos/data/ && ${COPYTREE_SHARE} \* ${DATADIR})

.include <bsd.port.mk>
