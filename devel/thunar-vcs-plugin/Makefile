# New ports collection makefile for:	thunar-vcs-plugin
# Date created: 	2008-10-15
# Whom:			Sergey V. Dyatko <sergey.dyatko@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	thunar-vcs-plugin
PORTVERSION=	0.1.4
PORTREVISION=	5
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/thunar-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Subversion plugin for Thunar

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	desktopfileutils gnomehack gtk20 glib20 intltool intlhack \
		pkgconfig
USE_XFCE=	configenv libexo libutil thunar
INSTALLS_ICONS=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	NLS "Enable Native Language Support" on \
		GIT "Enable Git support" off \
		SVN "Enable Subversion support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_GIT)
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
CONFIGURE_ARGS+=--enable-git
PLIST_SUB+=	GIT=""
.else
CONFIGURE_ARGS+=--disable-git
PLIST_SUB+=	GIT="@comment "
.endif

.if !defined(WITHOUT_SVN)
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion
CONFIGURE_ARGS+=--enable-subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-subversion
PLIST_SUB+=	SVN="@comment "
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
