# New ports collection makefile for:	xfmpc
# Date created:				21 Jan 2008
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfmpc
PORTVERSION=	0.2.0
PORTREVISION=	6
CATEGORIES=	audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A graphical MPD client focusing on low footprint

LIB_DEPENDS=	mpd.3:${PORTSDIR}/audio/libmpd

MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel

MAN1=	xfmpc.1

.include <bsd.port.mk>
