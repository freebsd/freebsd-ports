# New ports collection makefile for:	jamboree
# Date created:			08 Oct 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	jamboree
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jylefort@brutele.be
COMMENT=	A simple GNOME music player

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libglade2
USE_GSTREAMER=	vorbis mad gconf
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

OPTIONS=	DBUS "D-BUS support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DBUS)
LIB_DEPENDS+=		dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--enable-dbus
.endif

.include <bsd.port.post.mk>
