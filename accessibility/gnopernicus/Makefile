# New ports collection makefile for:	gnopernicus
# Date created:				11 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/gnopernicus/Makefile,v 1.85 2007/07/23 19:03:49 mezz Exp $
#

PORTNAME=	gnopernicus
PORTVERSION=	1.1.2
PORTREVISION=	9
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of accessibility apps for GNOME 2

LIB_DEPENDS=	gnome-mag.2:${PORTSDIR}/accessibility/gnome-mag

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui atspi gnomespeech
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags gtk+-2.0`" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	SED="${SED}"

GCONF_SCHEMAS=	brlmonitor.schemas gnopernicus.schemas remote.schemas
SHLIB_VERSION=	2
PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^F||' \
		${WRKSRC}/help/braille_monitor/C/brlmonitor-C.omf \
		${WRKSRC}/help/braille_monitor/es/brlmonitor-es.omf
	@${CP} ${FILESDIR}/gnopernicus-mag-config ${WRKSRC}/gnopi

.include <bsd.port.mk>
