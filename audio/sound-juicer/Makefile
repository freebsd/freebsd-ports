# New ports collection makefile for:	soundjuicer
# Date created:		20 Jan 2004
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sound-juicer
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean and lean CD ripper for GNOME2

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		gnome-media-profiles.0:${PORTSDIR}/audio/gnomemedia2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui nautiluscdburner
USE_GSTREAMER=	cdparanoia vorbis flac gconf
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--enable-ignore-missing-cd
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	sound-juicer.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)tests\(.*\)|\1\2|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
