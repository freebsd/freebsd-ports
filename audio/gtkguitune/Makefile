# New ports collection makefile for:	gtkguitune
# Date created:				12 Feb 2005
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkguitune
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/harpin_floh/mysoft/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	A guitar (and other instruments) tuner for GTK

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes

PLIST_FILES=	bin/gtkguitune

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CFLAGS+=	-fhuge-objects
.endif

.include <bsd.port.post.mk>
