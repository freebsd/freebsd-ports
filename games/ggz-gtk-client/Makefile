# ex:ts=8
# Ports collection makefile for:	ggz-gtk-client
# Date created:			Oct 22, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-gtk-client
PORTVERSION=	0.0.13
CATEGORIES=	games
MASTER_SITES=	http://mirrors.dotsrc.org/ggzgamingzone/ggz/%SUBDIR%/ \
		http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DIST_SUBDIR=	ggz

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - GTK+ Frontend

LIB_DEPENDS=	ggzcore.8:${PORTSDIR}/games/ggz-client-libs

USE_AUTOTOOLS=	libtool:15
USE_GCC=	3.3+
USE_GNOME=	gnometarget gtk20
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

MAN6=	ggz-gtk.6

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	depends on libggz which does not build on 4.x
.endif

.include <bsd.port.post.mk>

