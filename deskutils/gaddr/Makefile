# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gaddr
PORTVERSION=	1.1.4
PORTREVISION=	5
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.wirelesscouch.net/software/gaddr/ \
		http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	GTK 1.x address book

PLIST_FILES=	bin/gaddr
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS+=--enable-gnome
.endif

.include <bsd.port.post.mk>
