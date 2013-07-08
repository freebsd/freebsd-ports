# Created by: John Hixson <john@pcbsd.org>
# $FreeBSD$

PORTNAME=	pithos
PORTVERSION=	0.3.17
CATEGORIES=	audio
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	john@pcbsd.org
COMMENT=	Pandora client for the GNOME desktop

LICENSE=	GPLv3

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${LOCALBASE}/libdata/pkgconfig/notify-python.pc:${PORTSDIR}/devel/py-notify \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USE_PYTHON=	2.6+
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	yes
USE_GSTREAMER=	good bad python
PYDISTUTILS_PKGNAME=	${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s,../data/,${DATADIR}/," ${WRKSRC}/pithos/pithosconfig.py
	${REINPLACE_CMD} -e "s,Icon=pithos,${DATADIR}/media/icon.png," ${WRKSRC}/pithos.desktop

post-install:
	@${INSTALL} -o ${BINOWN} -g ${BINGRP} -m 555 \
		${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/data/ && ${COPYTREE_SHARE} \* ${DATADIR})

.include <bsd.port.mk>
