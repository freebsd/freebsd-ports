# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	1.11.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/stable/ \
		ftp://ftp.netc.pt/pub/freeciv/stable/ \
		ftp://ftp.pvv.ntnu.no/pub/freeciv/stable/

MAINTAINER=	sheldonh@freebsd.org

USE_XPM=	yes
USE_BZIP2=	yes
WANT_IMLIB=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_IMLIB)
USE_IMLIB=	yes
.else
CONFIGURE_ARGS=	--disable-gtktest
.endif

.include <bsd.port.post.mk>
