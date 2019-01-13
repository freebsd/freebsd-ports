# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

USE_GITHUB=	yes

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/gi/overrides/Gst.py:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylast>0:audio/py-pylast@${PY_FLAVOR}

USE_GNOME=	gtk30 pygobject3
USES=		python:3.4+
USE_PYTHON=	distutils autoplist optsuffix
USE_GSTREAMER1=	core good bad soup

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/pithos/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
