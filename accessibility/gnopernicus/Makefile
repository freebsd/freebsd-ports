# New ports collection makefile for:	gnopernicus
# Date created:				11 May 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/gnopernicus/Makefile,v 1.76 2006/04/14 14:42:45 mezz Exp $
#

PORTNAME=	gnopernicus
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	accessibility x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of accessibility apps for GNOME 2

LIB_DEPENDS=	gnome-mag.2:${PORTSDIR}/accessibility/gnomemag

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui atspi gnomespeech
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	SED="${SED}"

GCONF_SCHEMAS=	brlmonitor.schemas gnopernicus.schemas remote.schemas
SHLIB_VERSION=	4
PLIST_SUB=	SHLIB_VERSION=${SHLIB_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^F||' \
		${WRKSRC}/help/braille_monitor/C/brlmonitor-C.omf \
		${WRKSRC}/help/braille_monitor/es/brlmonitor-es.omf
	@${CP} ${FILESDIR}/gnopernicus-mag-config ${WRKSRC}/gnopi

.include <bsd.port.mk>
