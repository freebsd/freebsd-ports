# New ports collection makefile for:	soundjuicer
# Date created:		20 Jan 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/sound-juicer/Makefile,v 1.79 2008/03/10 20:39:31 mezz Exp $
#

PORTNAME=	sound-juicer
PORTVERSION=	2.22.0
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean and lean CD ripper for GNOME2

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnome-media \
		cdio.7:${PORTSDIR}/sysutils/libcdio \
    		tag.5:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner \
		gnomedocutils
USE_GSTREAMER=	cdparanoia vorbis flac gconf good
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

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
