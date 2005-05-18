# New ports collection makefile for:    UFRaw gimp plugin
# Date created:         		Sun 10 Apr 2005 14:44:15 BST
# Whom:                 		markm@FreeBSD.org
#
# $FreeBSD$

PORTNAME=		ufraw
PORTVERSION=		0.4
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ufraw

MAINTAINER=		markm@FreeBSD.org
COMMENT=		GIMP plug-in for raw digital camera image importing

RUN_DEPENDS=		gimp:${PORTSDIR}/graphics/gimp
LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			tiff.4:${PORTSDIR}/graphics/tiff

USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GNOME=		glib20 gnomehack intltool intlhack gtk20 libartlgpl2
WANT_GNOME=		yes
ALL_TARGET=		build
INSTALL_TARGET=		install-admin

.include <bsd.port.mk>
