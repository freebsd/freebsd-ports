# New ports collection makefile for:	soundjuicer
# Date created:		20 Jan 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/sound-juicer/Makefile,v 1.91 2009/03/18 04:24:29 marcus Exp $
#

PORTNAME=	sound-juicer
PORTVERSION=	2.26.1
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean and lean CD ripper for GNOME2

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
    		musicbrainz3.6:${PORTSDIR}/audio/libmusicbrainz3 \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media \
		cdio.8:${PORTSDIR}/sysutils/libcdio \
    		tag.6:${PORTSDIR}/audio/taglib \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		brasero-media.1:${PORTSDIR}/sysutils/brasero

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gconf2 libglade2 gnomedocutils
USE_GSTREAMER=	cdparanoia vorbis flac gconf good gio
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ignore-missing-cd
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		sound-juicer.1
GCONF_SCHEMAS=	sound-juicer.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)tests\(.*\)|\1\2|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' ${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
