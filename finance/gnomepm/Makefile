# Ports collection Makefile for:	gnomepm
# Date created:				16 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepm
PORTVERSION=	0.9.0
CATEGORIES=	misc gnome
MASTER_SITES=	http://www.geocities.com/lordzephyroth/
DISTNAME=	${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		ghttp.1:${PORTSDIR}/www/libghttp
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

USE_X_PREFIX=	yes

MAKE_ENV=	MKDIR="${MKDIR}"

.include <bsd.port.mk>
