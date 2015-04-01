# Created by: Vladimir Osintsev <oc@nm.ru>
# $FreeBSD$

PORTNAME=	mbox
PORTVERSION=	0.7.2
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	http://www.mbox.wz.cz/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program intended to help with organizing your music files

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ogg>0:${PORTSDIR}/audio/py-ogg \
		${PYTHON_PKGNAMEPREFIX}vorbis>0:${PORTSDIR}/audio/py-vorbis \
		lame:${PORTSDIR}/audio/lame \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		mplayer:${PORTSDIR}/multimedia/mplayer

WRKSRC=		${WRKDIR}/mBox-${PORTVERSION}
USES=		python:2 tar:bzip2
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+
WX_COMPS=	python

.include <bsd.port.mk>
