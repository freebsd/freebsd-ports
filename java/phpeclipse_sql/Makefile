# New ports collection makefile for:	phpeclipse_sql
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse_sql
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpeclipse
DISTNAME=	phpeclipse.sql_${PORTVERSION}beta

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse SQL Utility plugin for Eclipse IDE Framework

RUN_DEPENDS+=	${LOCALBASE}/eclipse/plugins/net.sourceforge.phpeclipse/plugin.xml:${PORTSDIR}/java/phpeclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/net.sourceforge.${DISTNAME:S/beta$//}

do-install:
	@${MKDIR} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.sql
.for f in phpeclipsesql.jar plugin.properties plugin.xml
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.sql
.endfor
	@${CP} -r ${WRKSRC}/icons ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.sql

.include <bsd.port.mk>
