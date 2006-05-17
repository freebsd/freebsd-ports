# New ports collection makefile for:	easytag-devel
# Date created:				15 Feb 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	easytag
PORTVERSION=	1.99.12
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	GTK2 Tag editor for MP3 and OGG files

LIB_DEPENDS=	id3:${PORTSDIR}/audio/id3lib \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2

MAN1=		easytag.1
CONFLICTS=	easytag-[0-9]*

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_GTK" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
