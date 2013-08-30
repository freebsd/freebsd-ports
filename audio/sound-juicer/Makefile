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

LIB_DEPENDS=	musicbrainz3.6:${PORTSDIR}/audio/libmusicbrainz3 \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media \
		cdio.13:${PORTSDIR}/sysutils/libcdio \
    		tag.1:${PORTSDIR}/audio/taglib \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		brasero-media.3:${PORTSDIR}/sysutils/brasero

USE_BZIP2=	yes
USES=		gettext gmake pathfix
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
