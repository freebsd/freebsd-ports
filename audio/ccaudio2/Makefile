# New ports collection makefile for:	ccaudio2
# Date created:	13 February 2008
# Whom:		gahr
#
# $FreeBSD$
#

PORTNAME=	ccaudio2
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	ccgnu2:${PORTSDIR}/devel/commoncpp \
    		ucommon.5:${PORTSDIR}/devel/ucommon \
		gsm.1:${PORTSDIR}/audio/gsm \
		speex.1:${PORTSDIR}/audio/speex

CONFLICTS=	ccaudio-[0-9]*

USE_GNOME=	gnomehack
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:PATH=${LOCALBASE}/include

.include <bsd.port.mk>
