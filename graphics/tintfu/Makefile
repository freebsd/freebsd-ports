# ex:ts=8
# Ports collection makefile for:	tintfu
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tintfu
PORTVERSION=	0.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GraphViz .dot file editor

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+

PLIST_FILES=	%%JAVAJARDIR%%/${DISTNAME}.jar \
		bin/tintfu

SUB_FILES=	tintfu.sh
SUB_LIST=	DISTNAME=${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/tintfu.sh ${PREFIX}/bin/tintfu

.include <bsd.port.mk>
