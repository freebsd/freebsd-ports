# New ports collection makefile for:	jamboree
# Date created:			08 Oct 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	jamboree
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.3

MAINTAINER=	jylefort@brutele.be
COMMENT=	A simple GNOME music player

LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		gstplay-0.6:${PORTSDIR}/multimedia/gstreamer-plugins \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libglade2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
