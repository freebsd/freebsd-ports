# New ports collection makefile for:	prune
# Date created:		25 Jun 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prune
PORTVERSION=	7
PORTREVISION=	1
CATEGORIES=	astro java
MASTER_SITES=	http://activityworkshop.net/software/prune/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_0${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Application for viewing, editing and converting GPS coordinate data

CONFLICTS=	graphviz-[0-9]*

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.5+

SUB_FILES=	prune.sh
SUB_LIST=	JARNAME=${DISTNAME}

PLIST_FILES=	bin/prune ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/prune.sh ${PREFIX}/bin/prune

.include <bsd.port.mk>
