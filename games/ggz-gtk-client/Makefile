# ex:ts=8
# Ports collection makefile for:	ggz-gtk-client
# Date created:			Oct 22, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-gtk-client
PORTVERSION=	0.0.12
CATEGORIES=	games
MASTER_SITES=	http://mirrors.dotsrc.org/ggzgamingzone/ggz/%SUBDIR%/ \
		http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - GTK+ Frontend

LIB_DEPENDS=	ggzcore.8:${PORTSDIR}/games/ggz-client-libs

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

.include <bsd.port.mk>
