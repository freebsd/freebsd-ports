# New ports collection makefile for:	gedit
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gedit
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gedit/0.9

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for Gnome Desktop Environment

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomeprint libglade gnomevfs
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

MAN1=		gedit.1

.include <bsd.port.mk>
