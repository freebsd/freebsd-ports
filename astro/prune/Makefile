# New ports collection makefile for:	prune
# Date created:		25 Jun 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prune
PORTVERSION=	10
CATEGORIES=	astro java
MASTER_SITES=	http://activityworkshop.net/software/prune/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Application for viewing, editing and converting GPS coordinate data

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.5+

SUB_FILES=	prune.sh
SUB_LIST=	JARNAME=${DISTNAME}

PLIST_FILES=	bin/prune-gps-tool ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

OPTIONS=	THREED "Support for 3D view of track" off

.include <bsd.port.options.mk>

.if defined(WITH_THREED)
RUN_DEPENDS+=	java3d>=1.5.2:${PORTSDIR}/java/java3d
.endif

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/prune.sh ${PREFIX}/bin/prune-gps-tool

.include <bsd.port.mk>
