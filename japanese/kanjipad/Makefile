# New ports collection makefile for:	kanjipad
# Date created:		30 March 2002
# Whom:			Christophe Juniet <cjuniet@entreview.com>
#
# $FreeBSD$
#

PORTNAME=	kanjipad
PORTVERSION=	1.2.1
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/users/otaylor/kanjipad/

MAINTAINER=	cjuniet@entreview.com

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_PERL5=	yes

post-install:
	strip ${PREFIX}/bin/kanjipad
	strip ${PREFIX}/bin/kpengine

.include <bsd.port.mk>
