# New ports collection makefile for:	libdvdread
# Date created:				24 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libdvdread
PORTVERSION=	0.8.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/

MAINTAINER=	3d@FreeBSD.org

USE_GMAKE=	yes
USE_AUTOMAKE=	yes
AUTOMAKE_ARGS=	--add-missing  --copy
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

USE_NEWGCC=	yes

# cf the excellent goat book:
#    http://sources.redhat.com/autobook/autobook/autobook_43.html
post-patch:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
