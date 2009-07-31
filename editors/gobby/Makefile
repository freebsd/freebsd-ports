# Ports collection makefile for:  gobby
# Date created:			  28 September 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	gobby
PORTVERSION=	0.4.10
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A free collaborative editor

LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		net6-1.3:${PORTSDIR}/net/net6 \
		obby-0.4:${PORTSDIR}/devel/obby

MAKE_JOBS_SAFE=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig gtksourceview2
USE_GMAKE=	yes

MAN1=	gobby.1

.include <bsd.port.mk>
