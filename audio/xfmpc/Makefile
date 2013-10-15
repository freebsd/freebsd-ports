# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfmpc
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical MPD client focusing on low footprint

LIB_DEPENDS=	libmpd.so:${PORTSDIR}/audio/libmpd

USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil

.include <bsd.port.mk>
