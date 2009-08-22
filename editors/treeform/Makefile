# New ports collection makefile for:	treeform
# Date created:				3 July 2007
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	treeform
PORTVERSION=	1.0.3
CATEGORIES=	editors java
MASTER_SITES=	SF/${PORTNAME}/TreeForm%20Unified/TreeForm%20${PORTVERSION}
DISTNAME=	TreeForm_1_0_3

MAINTAINER=	buganini@gmail.com
COMMENT=	A Linguistic Syntax/Semantics tree drawing editor

USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
SUB_FILES=	treeform

WRKSRC=		${WRKDIR}/TreeForm

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/treeform ${PREFIX}/bin
	cd ${WRKSRC} \
		&& ${INSTALL_DATA} TreeForm.jar ${JAVAJARDIR} \
		&& ${COPYTREE_SHARE} about.htm ${DATADIR} \
		&& ${COPYTREE_SHARE} help ${DATADIR} \
		&& ${COPYTREE_SHARE} image ${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
