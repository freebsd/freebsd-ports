# New ports collection makefile for:	phpeclipse_sql
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse_tidy
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	java editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpeclipse
DISTNAME=	phpeclipse.tidy_${PORTVERSION}preAlpha

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse HTML tidier plugin for Eclipse IDE Framework

BROKEN=		fix me

RUN_DEPENDS+=	${LOCALBASE}/eclipse/plugins/net.sourceforge.phpeclipse/plugin.xml:${PORTSDIR}/java/phpeclipse

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/net.sourceforge.${DISTNAME:S/preAlpha$//}

do-install:
	@${MKDIR} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.tidy
.for f in jtidy.jar plugin.properties plugin.xml
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.tidy
.endfor
	@${CP} -r ${WRKSRC}/icons ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.tidy
	@${RM} -r ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.tidy/icons/CVS
	@${RM} -r ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.tidy/icons/obj16/CVS

.include <bsd.port.mk>
