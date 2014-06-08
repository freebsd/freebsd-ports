# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	0.3.18
PORTREVISION=	1
CATEGORIES=	audio
DISTNAME=	${PORTVERSION}

MAINTAINER=	john@pcbsd.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	pithos
GH_PROJECT=	pithos
GH_COMMIT=	0770210

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_PYDISTUTILS=yes
USE_GSTREAMER=	good bad python
PYDISTUTILS_AUTOPLIST=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/pithos/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
