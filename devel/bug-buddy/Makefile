# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/bug-buddy/Makefile,v 1.44 2007/03/13 12:27:23 ahze Exp $
#

PORTNAME=	bug-buddy
PORTVERSION=	2.18.1
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME 2

LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		soup-2.2.8:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop gnomemenus \
		gnomedocutils evolutiondataserver
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	bug-buddy.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|' \
		${WRKSRC}/src/bugzilla.c

.include <bsd.port.mk>
