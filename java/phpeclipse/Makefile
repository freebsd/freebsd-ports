# New ports collection makefile for:	phpeclipse
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpeclipse
DISTNAME=	net.sourceforge.phpeclipse_${PORTVERSION}a

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse adds PHP support to the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

do-install:
	@${MKDIR} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse
.for f in phpeclipse.jar plugin.xml plugin.properties
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse
.endfor
	@${CP} -r ${WRKSRC}/icons ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse

.include <bsd.port.mk>
