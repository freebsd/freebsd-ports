# New ports collection makefile for:	phpeclipse-phphelp
# Date created:				22 Oct 2003
# Whom:					rtdean@cytherianage.net
#
# $FreeBSD$
#

PORTNAME=	phpeclipse_phphelp
PORTVERSION=	1.0.4
CATEGORIES=	java editors devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpeclipse
DISTNAME=	net.sourceforge.phpeclipse.phphelp_${PORTVERSION}

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	PHP Eclipse Help for the Eclipse IDE Framework

RUN_DEPENDS=	${LOCALBASE}/eclipse/plugins/net.sourceforge.phpeclipse/plugin.xml:${PORTSDIR}/java/phpeclipse

NO_BUILD=	yes
USE_ZIP=	yes

do-install:
	@${MKDIR} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.phphelp
.for f in doc.zip phphelp.jar phphelp.xml plugin.properties plugin.xml
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/eclipse/plugins/net.sourceforge.phpeclipse.phphelp
.endfor

.include <bsd.port.mk>
