# New ports collection makefile for:	gnomekiss
# Date created:				4 Apr 2001
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gnomekiss
PORTVERSION=	1.1
CATEGORIES=	games gnome
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njl98r/code/kiss/
DISTNAME=	gnomekiss-${PORTVERSION}

MAINTAINER=	umeno@rr.iij4u.or.jp

USE_X_PREFIX=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
