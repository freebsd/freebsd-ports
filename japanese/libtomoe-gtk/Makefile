# New ports collection makefile for:	ja-libtomoe-gtk
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtomoe-gtk
PORTVERSION=	0.5.1
#PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=tomoe/23909

MAINTAINER=	ume@FreeBSD.org
COMMENT=	TOMOE GTK+ library

LIB_DEPENDS=	tomoe.1:${PORTSDIR}/japanese/tomoe \
		gucharmap.6:${PORTSDIR}/deskutils/gucharmap

USE_GNOME=	lthack gnomehack gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
