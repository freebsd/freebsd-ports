# New ports collection makefile for:	acovea-gtk
# Date created:		2006-08-01
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	acovea-gtk
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.coyotegulch.com/distfiles/

MAINTAINER=	trasz@freebsd.org
COMMENT=	GTK+ front-end to ACOVEA

LIB_DEPENDS=	acovea-5.1.5:${PORTSDIR}/devel/acovea \
		evocosm-3.1.1:${PORTSDIR}/devel/libevocosm \
		coyotl-3.1.4:${PORTSDIR}/devel/libcoyotl \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${PREFIX}/include/ LDFLAGS=-L${PREFIX}/lib/

.include <bsd.port.pre.mk>

pre-install:
	${CHMOD} 755 ${WRKSRC}/install-sh

.include <bsd.port.post.mk>
