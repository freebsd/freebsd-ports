# Ports collection makefile for:  gobby
# Date created:			  28 September 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	gobby
PORTVERSION=	0.2.2
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	A free collaborative editor

LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		net6-1.1.0:${PORTSDIR}/net/net6 \
		obby-0.2.0:${PORTSDIR}/devel/obby

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig gtksourceview
USE_GCC=	3.4

PLIST_FILES=	bin/gobby

.include <bsd.port.mk>
