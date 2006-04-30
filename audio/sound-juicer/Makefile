# New ports collection makefile for:	soundjuicer
# Date created:		20 Jan 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/sound-juicer/Makefile,v 1.49 2006/04/14 15:06:00 ahze Exp $
#

PORTNAME=	sound-juicer
PORTVERSION=	2.14.3
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean and lean CD ripper for GNOME2

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnomemedia2 \
		cdio.6:${PORTSDIR}/sysutils/libcdio

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner \
		gnomedocutils
USE_GSTREAMER=	cdparanoia vorbis flac gconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ignore-missing-cd
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	sound-juicer.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)tests\(.*\)|\1\2|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|--parents|-p|g' \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
