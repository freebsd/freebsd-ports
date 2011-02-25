# New ports collection makefile for:	glipper
# Date created:		2007-10-21
# Whom:			Yuri Pankov <yuri.pankov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	glipper
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clipboard manager for the GNOME panel

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intltool pygnomedesktop pygnomeextras
USE_PYTHON=	2.5+
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/libexec

GCONF_SCHEMAS=	glipper.schemas

.include <bsd.port.mk>
