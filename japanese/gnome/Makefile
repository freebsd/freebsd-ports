# New ports collection makefile for:	gnome
# Date created:		02 November 2000
# Whom:			Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome
PORTVERSION=	1.4.1b2
PORTREVISION=	5
CATEGORIES=	japanese x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnome.5:${PORTSDIR}/japanese/gnomelibs \
		gal.22:${PORTSDIR}/japanese/gal
RUN_DEPENDS=	gnumeric:${PORTSDIR}/japanese/gnumeric

NO_BUILD=	yes

USE_PYTHON=	yes

do-install:	# empty

.include <bsd.port.mk>
