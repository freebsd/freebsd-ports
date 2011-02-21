# New ports collection makefile for:	ccaudio2
# Date created:	13 February 2008
# Whom:		gahr
#
# $FreeBSD$
#

PORTNAME=	ccaudio2
PORTVERSION=	2.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	ccgnu2:${PORTSDIR}/devel/commoncpp \
    		ucommon.4:${PORTSDIR}/devel/ucommon

CONFLICTS=	ccaudio-[0-9]*

USE_GNOME=	gnometarget gnomehack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	audiotool.1 tonetool.1 ccaudio2-config.1

PLIST_SUB+=	CCVERSION=1.0

.include <bsd.port.mk>
