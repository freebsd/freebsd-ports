# New ports collection makefile for: squeeze
# Date created: 07 Jun 2010
# Whom: markand
#
# $FreeBSD$
#

PORTNAME=	squeeze
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	archivers xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	markand@malikania.fr
COMMENT=	Squeeze is a modern and advanced archive manager

MAKE_JOB_SAFE=	yes

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

USE_XFCE=	configenv panel thunar thunarvfs
USE_XORG=	x11
USE_GNOME=	gnomehack gnometarget gtk20 glib20 intltool intlhack pkgconfig
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

OPTIONS=	GTKDOC "Enable GTK html documentation" off

.include <bsd.port.options.mk>

.if defined(WITH_GTKDOC)
PLIST_SUB=	GTKDOC=""
.else
PLIST_SUB=	GTKDOC="@comment "
.endif

post-patch:
# Needed to remove gtk-doc installation
.if !defined(WITH_GTKDOC)
	@${REINPLACE_CMD} -e "s|docs||g" ${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
