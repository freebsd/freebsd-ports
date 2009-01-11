# New ports collection makefile for:	devhelp
# Date created:				29 May 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/devhelp/Makefile,v 1.10 2009/01/09 22:20:28 kwm Exp $

PORTNAME=	devhelp
PORTVERSION=	0.21
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Developer help browser for GNOME 2

USE_BZIP2=	yes
USE_XORG=	x11
USE_GETTEXT=	yes
USE_GECKO=	firefox xulrunner
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui libwnck
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	devhelp.schemas
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gecko=${GECKO}

OPTIONS=		GEDIT "Enable GEdit plug-in support" off

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

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
.endif

.include <bsd.port.post.mk>
