# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/audio/sound-juicer/Makefile,v 1.102 2010/09/29 13:19:43 kwm Exp $

PORTNAME=	sound-juicer
PORTVERSION=	2.32.0
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean, and lean CD ripper for GNOME2

LIB_DEPENDS=	libmusicbrainz3.so:${PORTSDIR}/audio/libmusicbrainz3 \
		libgnome-media-profiles.so:${PORTSDIR}/audio/gnome-media \
		libcdio.so:${PORTSDIR}/sysutils/libcdio \
		libtag.so:${PORTSDIR}/audio/taglib \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libbrasero-media.so:${PORTSDIR}/sysutils/brasero

USE_BZIP2=	yes
NO_STAGE=	yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
USE_GNOME=	intlhack gnomeprefix gconf2 libglade2 gnomedocutils
USE_GSTREAMER=	cdparanoia vorbis flac gconf good gio
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ignore-missing-cd
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		sound-juicer.1
GCONF_SCHEMAS=	sound-juicer.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)tests\(.*\)|\1\2|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' ${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
