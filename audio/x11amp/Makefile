# New ports collection makefile for:    x11amp
# Date created:         13 Jul 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x11amp
PORTVERSION=	0.9.b1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/misc/x11amp/0.9/ \
		ftp://ftp.sci-nnov.ru/pub/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/}

MAINTAINER=	dburr@FreeBSD.org
COMMENT=	X11-based MP3 player with nice graphical interface

USE_XLIB=	yes
USE_GNOME=	gtk12 esound
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libx11amp/configure
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

post-extract:
	@${CP} ${FILESDIR}/main.xpm ${WRKSRC}/x11amp/defskin

.include <bsd.port.post.mk>
