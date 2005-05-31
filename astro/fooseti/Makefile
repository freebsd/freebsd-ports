# Ports collection makefile for:	fooseti
# Date created:				28 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	fooseti
PORTVERSION=	0.6.6
PORTREVISION=	4
CATEGORIES=	astro
# mastersite disappeared February 2003
MASTER_SITES=	# http://www-personal.engin.umich.edu/~agorski/fooseti/

DEPRECATED=	"master site disappeared, last release 2001"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ frontend to SETI@Home

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_FILES=	bin/fooseti
USE_GETTEXT=	yes
USE_GNOME=	gtk12

.include <bsd.port.mk>
