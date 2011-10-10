# New ports collection makefile for:    	monodevelop
# Date created:         			20040906
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.48 2007/11/07 20:30:04 killfill Exp $
#

PORTNAME=	monodevelop
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	IDE for the .NET platform

BUILD_DEPENDS=	mautil:${PORTSDIR}/devel/mono-addins \
		update-desktop-database:${PORTSDIR}/devel/desktop-file-utils
RUN_DEPENDS=	${LOCALBASE}/lib/libgdiplus.a:${PORTSDIR}/x11-toolkits/libgdiplus \
		exctags:${PORTSDIR}/devel/ctags \
		mautil:${PORTSDIR}/devel/mono-addins

USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
MAN1=		mdtool.1 monodevelop.1
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

OPTIONS=	MONOEXT "Enable extensions for Mono development" on \
		GIT "Enable git support" on \
		SVN "Enable subversion support" on

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MONOEXT)
CONFIGURE_ARGS+=--enable-monoextensions
PLIST_SUB+=	MONOEXT=""
.else
CONFIGURE_ARGS+=--disable-monoextensions
PLIST_SUB+=	MONOEXT="@comment "
.endif

.if !defined(WITHOUT_GIT)
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
CONFIGURE_ARGS+=--enable-git
PLIST_SUB+=	GIT=""
.else
CONFIGURE_ARGS+=--disable-git
PLIST_SUB+=	GIT="@comment "
.endif

.if !defined(WITHOUT_SVN)
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
CONFIGURE_ARGS+=--enable-subversion
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-subversion
PLIST_SUB+=	SVN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]gnome_data[)]/mime$$|(prefix)/share/mime|g ; \
		s|[(]gnome_data[)]/mime/packages$$|(prefix)/share/mime/packages|g ; \
		s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/monodevelop.in \
		${WRKSRC}/mdtool.in

post-install:
	@-update-desktop-database

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
