# Created by: sugimura@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	vep
PORTVERSION=	1.1.0.1
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/ve/downloads/drops/R-1.1.0.1-200509071822/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-examples
DISTNAME=	VE-examples-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Visual Editor Project for the Eclipse IDE (examples)

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	RELEASEVERSION=1.1.0.1

NO_STAGE=	yes
do-install:
		@${MKDIR} ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/lib/eclipse

.include <bsd.port.mk>
