# ex:ts=8
# New ports collection makefile for:	easytag
# Date created:			May 17, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	easytag
PORTVERSION=	0.30d
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	easytag-${PORTVERSION:S/d$//}

PATCHFILES=	patch_easytag_030_030a.diff patch_easytag_030a_030b.diff \
		patch_easytag_030b_030c.diff patch_easytag_030c_030d.diff
PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	${PORTNAME}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	roddie@krweb.net
COMMENT=	Tag editor for MP3 and OGG files

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		FLAC.5:${PORTSDIR}/audio/flac

MAN1=		easytag.1

USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIG_SHELL="${SH}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
