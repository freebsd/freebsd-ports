# New ports collection makefile for:   stars-1.0
# Date created:		10 Jul 1996
# Whom:			searle
#
# $FreeBSD$
#

PORTNAME=	stars
PORTVERSION=	1.0
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.planetmirror.com/pub/hpux/X11/Demos/stars-1.0/ \
		http://www.planetmirror.com/pub/hpux/X11/Demos/stars-1.0/
DISTFILES=	stars-1.0-ss-11.00.tar.gz

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

CC?=		cc
CFLAGS?=	-O2

do-build:
	$(CC) -I$(PREFIX)/include $(CFLAGS) -c $(WRKSRC)/xwin.c -o $(WRKSRC)/xwin.o
	$(CC) -I$(PREFIX)/include $(CFLAGS) -c $(WRKSRC)/main.c -o $(WRKSRC)/main.o
	$(CC) $(WRKSRC)/main.o $(WRKSRC)/xwin.o -L$(PREFIX)/lib -lX11 -lm -o $(WRKSRC)/stars

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/stars $(PREFIX)/bin/stars

.include <bsd.port.mk>
