# New ports collection makefile for:	wmjupiter
# Date created:				Tue Jan 15 17:28:49 EST 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmjupiter
PORTVERSION=	1.1
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://www.inxsoft.net/wmjupiter/

MAINTAINER=	pat@FreeBSD.org

WRKSRC=		${WRKDIR}/wmJupiter
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes

pre-patch:
	@${PERL} -pi.orig -e 's|values.h|float.h|; s|MAXDOUBLE|DBL_MAX|g' \
		${WRKSRC}/wmJupiter.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmJupiter ${PREFIX}/bin

.include <bsd.port.mk>
