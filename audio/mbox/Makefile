# New ports collection makefile for:	mbox
# Date created:		2004-11-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mbox
PORTVERSION=	0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://www.mbox.wz.cz/src/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	WxGTK GUI for audio organizing and converting

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame
RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		img2png:${PORTSDIR}/x11-toolkits/py-wxPython

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/mBox-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
