# New ports collection makefile for: 	OmegaT
# Date created:				11 May 2008
# Whom:					Rodrigo OSORIO <rodrigo@bebik.net>
# $FreeBSD$
#

PORTNAME=	omegaT
PORTVERSION=	1.7.3.2
CATEGORIES=	editors java x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	omegat
DISTNAME=	OmegaT_1.7.3_02_Source

MAINTAINER=	rodrigo@bebik.net
COMMENT=	A powerfull translation memory application written in Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

USE_ZIP=	yes
DIST_SUBDIR=	${PORTNAME}
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
WRKSRC=		${WRKDIR}/

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	omegaT.sh omegat.prefs

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/omegaT.sh ${PREFIX}/bin/${PORTNAME}
	@cd ${WRKDIR} && ${COPYTREE_SHARE} ${PORTNAME} ${JAVASHAREDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/omegat.prefs ${JAVASHAREDIR}/${PORTNAME}

post-build:
	@cd ${WRKDIR} && ${MV} 'dist' ${PORTNAME}

.include <bsd.port.mk>
