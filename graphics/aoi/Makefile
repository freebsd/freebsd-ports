# New ports collection makefile for:	Art Of Illusion
# Date created:				Fri Jun 21 17:10:56 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aoi
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aoi
DISTNAME=	AoI${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Java written 3D modelling and rendering studio

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION}

EXTRACT_BEFORE_ARGS=	-a -q

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAR_PLUGIN_FILES=	OSSpecific.jar Renderers.jar Tools.jar Translators.jar
JAR_FILES=	ArtOfIllusion.jar ${JAR_PLUGIN_FILES:S,^,Plugins/,}
SUB_FILES=	aoi.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	HISTORY LICENSE README
.endif
PLIST_FILES=	${JAR_FILES:S,^,%%DATADIR%%/,} bin/aoi
PLIST_DIRS=	%%DATADIR%%/Plugins %%DATADIR%%

do-install:
	@${MKDIR} ${DATADIR}/Plugins
	cd ${WRKSRC} \
	  && ${FIND} ${JAR_FILES} -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/aoi.sh ${PREFIX}/bin/aoi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
