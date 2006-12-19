# New ports collection makefile for:	menueditor
# Date created:				22 March 2005
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#    $MCom: ports/deskutils/alacarte/Makefile,v 1.10 2006/10/10 18:48:41 marcus Exp $

PORTNAME=	alacarte
PORTVERSION=	0.10.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An editor for the freedesktop.org menu specification

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix pygnomedesktop intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GMSGFMT="${LOCALBASE}/bin/msgfmt"

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|' \
		${WRKSRC}/Alacarte/MenuEditor.py
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Alacarte/DialogHandler.py \
	    ${WRKSRC}/Alacarte/util.py
	@${REINPLACE_CMD} -e 's|gmsgfmt|msgfmt|g ; \
	    	s|python2.4|${PYTHON_VERSION}|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
