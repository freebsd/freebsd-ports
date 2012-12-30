# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		FLAC.10:${PORTSDIR}/audio/flac \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		mp4v2.10:${PORTSDIR}/multimedia/mp4v2 \
		tag:${PORTSDIR}/audio/taglib

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

PORTSCOUT=	limit:^1\.

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-musicbrainz
MAKE_JOBS_SAFE=	yes

post-configure:
	${CHMOD} 755 ${WRKSRC}/admin/install-sh

.include <bsd.port.mk>
