# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	0.9
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	makc@issp.ac.ru
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		FLAC.7:${PORTSDIR}/audio/flac \
		ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
