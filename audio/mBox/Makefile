# New ports collection makefile for:	mBox
# Date created:				01 Sep 2004
# Whom:					Vladimir Osintsev <oc@nm.ru>
# $FreeBSD$

PORTNAME=	mBox
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mbox.wz.cz/src/
DISTNAME= 	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	oc@nm.ru
COMMENT= 	Program intended to help with organizing your music files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython \
		${PYTHON_SITELIBDIR}/ogg/__init__.py:${PORTSDIR}/audio/py-ogg \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS= 	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

USE_X_PREFIX= 	yes
USE_PYTHON= 	2.2+
USE_BZIP2=	yes
PYTHON_SETUP= 	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py
WRKSRC= 	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD= 	yes

do-install:
	(cd ${WRKSRC} && ${PYTHON_SETUP} install --prefix=${PREFIX})

.include <bsd.port.mk>
