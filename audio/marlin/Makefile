# New ports collection makefile for:	marlin
# Date created:				16 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	marlin
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Sample editor for GNOME 2 using Gstreamer backend

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		uuid.1:${PORTSDIR}/sysutils/e2fsprogs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget intlhack libgnomeui
USE_GSTREAMER=	flac gconf mad vorbis
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lcam"

GCONF_SCHEMAS=	marlin.schemas

.if !defined(PACKAGE_BUILDING) || defined(WITH_LAME)
USE_GSTREAMER+=	lame
.endif

.include <bsd.port.mk>
