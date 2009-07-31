# New ports collection makefile for:	xfmpc
# Date created:				21 Jan 2008
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfmpc
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	audio xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A graphical MPD client focusing on low footprint

LIB_DEPENDS=	mpd.1:${PORTSDIR}/audio/libmpd

MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libgui libutil panel

.include <bsd.port.mk>
