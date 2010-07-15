# New ports collection makefile for:	eclipse-aptana
# Date created:		2007-11-14
# Whom:			Nicola Vitale	<nivit@FreeBSD.org>
#
# $FreeBSD$
#

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

JAVA_VERSION=	1.5+

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_JAVA=	yes
USE_ZIP=	yes

do-install:
	@(cd ${WRKDIR} && ${CP} -R features ${PREFIX}/lib/eclipse && ${CP} -R plugins ${PREFIX}/lib/eclipse;)

.include <bsd.port.mk>
