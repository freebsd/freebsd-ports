# New ports collection makefile for: 	OmegaT
# Date created:				11 May 2008
# Whom:					Rodrigo OSORIO <rodrigo@bebik.net>
# $FreeBSD$
#

PORTNAME=	omegaT
PORTVERSION=	1.8.1.5
CATEGORIES=	editors java x11
MASTER_SITES=	SF/${PORTNAME:L}/OmegaT%201.8%20%28Current%29/OmegaT%201.8.1%20update%205
DISTNAME=	OmegaT_1.8.1_05_Source

MAINTAINER=	rodrigo@bebik.net
COMMENT=	A powerfull translation memory application written in Java

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper
BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

USE_ZIP=	yes
DIST_SUBDIR=	${PORTNAME}
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
WRKSRC=		${WRKDIR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	omegaT.sh omegat.prefs

DESKTOP_ENTRIES="OmegaT" "Translation memory application" \
		"${DATADIR}/images/OmegaT.png" \
		"omegaT" "Application;Office;WordProcessor;" \
		false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/omegaT.sh ${PREFIX}/bin/${PORTNAME}
	@cd ${WRKDIR} && ${COPYTREE_BIN}  ${PORTNAME}  ${JAVASHAREDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/omegat.prefs ${JAVASHAREDIR}/${PORTNAME}

post-build:
	@cd ${WRKDIR} && ${MV} 'dist' ${PORTNAME}

.include <bsd.port.mk>
