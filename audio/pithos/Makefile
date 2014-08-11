# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	1.0.0
CATEGORIES=	audio
DISTNAME=	${PORTVERSION}

MAINTAINER=	kmoore@freebsd.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	pithos
GH_PROJECT=	pithos
GH_COMMIT=	1f5975e

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py3-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py3-dbus \
		${PYTHON_SITELIBDIR}/gi/overrides/Gst.py:${PORTSDIR}/multimedia/py3-gstreamer1 \
		${PYTHON_PKGNAMEPREFIX}pylast>0:${PORTSDIR}/audio/py3-pylast \
		git:${PORTSDIR}/devel/git

USE_GNOME=	gtk30 py3gobject3
USE_PYTHON=	3
USE_PYDISTUTILS=yes
USE_GSTREAMER=	core good bad soup
PYDISTUTILS_AUTOPLIST=	yes
INSTALLS_EGGINFO=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/pithos/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
