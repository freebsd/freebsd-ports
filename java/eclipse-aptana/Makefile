# Created by: Nicola Vitale	<nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aptana
PORTVERSION=	1.2.2.024747
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	http://update1.aptana.org/studio/3.2/024747/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	aptana_update_${PORTVERSION:E}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Aptana Web Development Tools (Eclipse plugin)

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

CONFLICTS_INSTALL=	eclipse-aptana-[2-9]*

USES=		zip
JAVA_VERSION=	1.6+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes

do-install:
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/lib/eclipse)

.include <bsd.port.mk>
