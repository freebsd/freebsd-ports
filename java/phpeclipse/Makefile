# New ports collection makefile for:	phpeclipse
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse
PORTVERSION=	1.1.1
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpeclipse
DISTNAME=	PHPEclipse${PORTVERSION}-2004-10-24

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse adds PHP support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}

do-install:
	@${CP} -r ${WRKSRC}/features ${PREFIX}/eclipse
	@${CP} -r ${WRKSRC}/plugins ${PREFIX}/eclipse

.include <bsd.port.mk>
