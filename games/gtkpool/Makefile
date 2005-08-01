# New ports collection makefile for:	GTKPool
# Date created:				31 Jul 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkpool
PORTVERSION=	0.5.0
CATEGORIES=	games
MASTER_SITES=	http://gtkpool.seul.org/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A 2D pool game using the GTK+ toolkit

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -DHAVE_CONFIG_H -I. -I.. `gtk-config --cflags` `gtk-config --libs`"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/share/gtkpool,${DATADIR},' \
		${WRKSRC}/gtkpool/application.cpp ${WRKSRC}/gtkpool/options.cpp

.include <bsd.port.mk>
