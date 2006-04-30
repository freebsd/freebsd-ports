# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/audio/gnomemedia2/Makefile,v 1.95 2006/04/13 07:52:30 bland Exp $
#

PORTNAME=	gnomemedia2
PORTVERSION=	2.14.0
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-media/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-media-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the GNOME 2 desktop

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop \
		gail nautiluscdburner
USE_GSTREAMER=	esound gconf good
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	CDDB-Slave2.schemas gnome-audio-profiles.schemas \
		gnome-cd.schemas gnome-sound-recorder.schemas \
		gnome-volume-control.schemas

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|[$$][(]CDROM_HOST[)]|freebsd|g' \
		${WRKSRC}/gnome-cd/Makefile.in
.if ${OSVERSION} > 501107
	@${REINPLACE_CMD} -e 's|acd0c|acd0|' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
