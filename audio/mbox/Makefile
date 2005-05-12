# New ports collection makefile for:	mBox
# Date created:				01 Sep 2004
# Whom:					Vladimir Osintsev <oc@nm.ru>
# $FreeBSD$

PORTNAME=	mbox
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mbox.wz.cz/src/

MAINTAINER=	oc@nm.ru
COMMENT=	Program intended to help with organizing your music files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24 \
		${PYTHON_SITELIBDIR}/ogg/__init__.py:${PORTSDIR}/audio/py-ogg \
		${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mplayer:${PORTSDIR}/multimedia/mplayer
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/mBox-${PORTVERSION}

.include <bsd.port.mk>
