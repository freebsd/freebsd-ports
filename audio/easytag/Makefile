# ex:ts=8
# New ports collection makefile for:	easytag
# Date created:			May 17, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	easytag
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Tag editor for MP3 and OGG files

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		FLAC.7:${PORTSDIR}/audio/flac

MAN1=		easytag.1
CONFLICTS=	easytag-devel-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
