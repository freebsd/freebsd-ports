# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	john@pcbsd.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

USE_GITHUB=	yes

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py3-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py3-dbus \
		${PYTHON_SITELIBDIR}/gi/overrides/Gst.py:multimedia/py3-gstreamer1 \
		${PYTHON_PKGNAMEPREFIX}pylast>0:audio/py3-pylast \
		git:devel/git

USE_GNOME=	gtk30 py3gobject3
USES=		python:3
USE_PYTHON=	distutils autoplist
USE_GSTREAMER=	core good bad soup

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/pithos/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
