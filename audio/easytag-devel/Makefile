# ex:ts=8
# New ports collection makefile for:	easytag
# Date created:			May 17, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	easytag
PORTVERSION=	0.24
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	d.marks@student.umist.ac.uk

LIB_DEPENDS=	id3-3.7.13:${PORTSDIR}/audio/id3lib \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
