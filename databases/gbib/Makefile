# New ports collection makefile for:	gbib
# Date created:			26 February 2002
# Whom:				Christian Brueffer (chris@unixpages.org)
#
# $FreeBSD$
#

PORTNAME=	gbib
PORTVERSION=	0.1.1b
CATEGORIES=	databases editors gnome
MASTER_SITES=	ftp://ftp.seul.org/pub/gbib/src/ \
		http://www.unixpages.org/distfiles/

MAINTAINER=	chris@unixpages.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
GNU_CONFIGURE=	yes

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
