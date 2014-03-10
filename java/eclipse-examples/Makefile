# Created by: olgeni@FreeBSD.org
# $FreeBSD$

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

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	cd ${WRKSRC}/eclipse && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/lib/eclipse

.include <bsd.port.mk>
