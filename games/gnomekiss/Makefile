# New ports collection makefile for:	gnomekiss
# Date created:				4 Apr 2001
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gnomekiss
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njl98r/code/kiss/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	GNOME version of Kisekae Set System

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		gnomekiss.1

.include <bsd.port.mk>
