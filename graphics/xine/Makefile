# New ports collection makefile for:    xine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=		xine
PORTVERSION=		0.3.2
CATEGORIES=		graphics
MASTER_SITES=		http://xine.sourceforge.net/files/
DISTNAME=		${PORTNAME}_${PORTVERSION}

MAINTAINER=		roman@xpert.com

USE_LIBTOOL=		yes
USE_X_PREFIX=		yes
USE_IMLIB=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=			xine.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
