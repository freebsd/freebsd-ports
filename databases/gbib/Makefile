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

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
BROKEN=		"Does not build on 5.0"
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
