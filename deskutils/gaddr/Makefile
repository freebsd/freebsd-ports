# New ports collection makefile for:	gaddr
# Date created:			8 August 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaddr
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A GTK (and optionally, GNOME) address book

PLIST_FILES=	bin/gaddr
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS+=--enable-gnome
.endif

.include <bsd.port.post.mk>
