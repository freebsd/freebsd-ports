# New ports collection makefile for:	GTKPool
# Date created:				31 Jul 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkpool
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://gtkpool.seul.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 2D pool game using the GTK+ toolkit

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_PERL5=	yes
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-O2 -O0 -Wall `gtk-config --cflags` -lgtk -lgdk -lglib -lm -lX11,${CXXFLAGS} `gtk-config --cflags` `gtk-config --libs`,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/usr/local/share/gtkpool,${DATADIR},' \
		${WRKSRC}/gtkpool/application.cpp ${WRKSRC}/gtkpool/options.cpp

.include <bsd.port.mk>
