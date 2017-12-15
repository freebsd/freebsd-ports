# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	jhixson@gmail.com
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

USE_GITHUB=	yes

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus@${FLAVOR} \
		${PYTHON_SITELIBDIR}/gi/overrides/Gst.py:multimedia/py-gstreamer1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylast>0:audio/py-pylast@${FLAVOR} \
		git:devel/git

USE_GNOME=	gtk30 py3gobject3
USES=		python:3.4+
USE_PYTHON=	distutils autoplist optsuffix
USE_GSTREAMER=	core good bad soup

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/pithos/data/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
