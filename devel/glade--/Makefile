# New ports collection makefile for:	glade--
# Date created:				7th October 2000
# Whom:			Shinya FUJIE <fujie@tk.elec.waseda.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	glademm
PORTVERSION=	0.5.11
CATEGORIES=	devel gnome
MASTER_SITES=	http://home.wtal.de/petig/Gtk/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/5./5_/}

MAINTAINER=	fujie@tk.elec.waseda.ac.jp

RUN_DEPENDS=	glade:${PORTSDIR}/devel/glade
LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes

post-patch:
	@${PERL} -pi -e 's|%%GTK_CONFIG%%|${GTK_CONFIG}|g' \
		${WRKSRC}/src/glade--.cc
	@${PERL} -pi -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/Cxx.cc

.include <bsd.port.mk>
