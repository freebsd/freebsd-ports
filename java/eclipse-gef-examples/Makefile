# New ports collection makefile for:	eclipse-gef-examples
# Date created:				July 8, 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gef
PORTVERSION=	3.0
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/gef/downloads/drops/R-3.0-200406251257/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-examples
DISTNAME=	GEF-examples-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Graphical Editing Framework for the Eclipse IDE (examples)

RUN_DEPENDS=    ${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
