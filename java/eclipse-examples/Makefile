# New ports collection makefile for:	eclipse-examples
# Date created:				July 3, 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	examples
PORTVERSION=	3.0
PORTREVISION=	6
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-3.0-200406251208
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Examples for the Eclipse IDE

RUN_DEPENDS=    ${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/lib/eclipse

.include <bsd.port.mk>
