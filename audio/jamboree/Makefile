# New ports collection makefile for:	jamboree
# Date created:			08 Oct 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	jamboree
PORTVERSION=	0.3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3

MAINTAINER=	jylefort@brutele.be
COMMENT=	A simple GNOME music player

LIB_DEPENDS+=	gstplay-0.6:${PORTSDIR}/multimedia/gstreamer-plugins \
		id3tag:${PORTSDIR}/audio/mad \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libglade2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
