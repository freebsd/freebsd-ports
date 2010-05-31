# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/devhelp/Makefile,v 1.32 2010/03/30 15:51:07 avl Exp $

PORTNAME=	devhelp
PORTVERSION=	2.30.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Developer help browser for GNOME 2

LIB_DEPENDS=	webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2 \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_BZIP2=	yes
USE_XORG=	x11
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui libwnck
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"

OPTIONS=		GEDIT "Enable GEdit plug-in support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
.else
PLIST_SUB+=	GEDIT="@comment "
.endif

post-patch:
.if defined(WITHOUT_GEDIT)
	@${REINPLACE_CMD} -e 's|gedit-plugin||' \
		${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_SINGLE_INCLUDES||g' \
		${WRKSRC}/src/Makefile.in
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/gconf/schemas
	@${CP} ${WRKSRC}/data/devhelp.schemas ${PREFIX}/etc/gconf/schemas

.include <bsd.port.post.mk>
