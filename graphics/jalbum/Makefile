# New ports collection makefile for:	jalbum
# Date created:				20 March 2005
# Whom:					Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	jalbum
PORTVERSION=	8.3.5
CATEGORIES=	graphics java
MASTER_SITES=	http://jalbum.net/download/
DISTNAME=	Jalbum${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Web photo album generator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/Jalbum

USE_ZIP=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.5+
# Only works with native bsdjava (breaks with linux and diablo versions)
JAVA_OS=	native
JAVA_VENDOR=	bsdjava
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jalbum.sh

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${TAR} -cf - * | ${TAR} -xf - -C ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum.sh ${PREFIX}/bin/jalbum

.include <bsd.port.mk>
