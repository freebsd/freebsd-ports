# New ports collection makefile for:	jamboree
# Date created:			08 Oct 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	jamboree
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jylefort@brutele.be
COMMENT=	A simple GNOME music player

LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libglade2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-dbus

OPTIONS=	XINE "use xine instead of GStreamer" off

.include <bsd.port.pre.mk>

.if defined(WITH_XINE)
LIB_DEPENDS+=		xine.9:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--enable-xine
.else
USE_GNOME+=		gstreamerplugins
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's/GST_VER=0\.7\.4/GST_VER=0.8/; s/(gstreamer(-[a-z]+)?|gst-inspect)-0\.7/\1-0.8/g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
