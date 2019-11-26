# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	treeform
PORTVERSION=	1.0.3
CATEGORIES=	editors java
MASTER_SITES=	SF/${PORTNAME}/TreeForm%20Unified/TreeForm%20${PORTVERSION}
DISTNAME=	TreeForm_1_0_3

MAINTAINER=	buganini@gmail.com
COMMENT=	Linguistic Syntax/Semantics tree drawing editor

USES=		zip
NO_BUILD=	yes
USE_JAVA=	yes
SUB_FILES=	treeform

WRKSRC=		${WRKDIR}/TreeForm

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/treeform ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} \
		&& ${INSTALL_DATA} TreeForm.jar ${STAGEDIR}${JAVAJARDIR} \
		&& ${COPYTREE_SHARE} about.htm ${STAGEDIR}${DATADIR} \
		&& ${COPYTREE_SHARE} help ${STAGEDIR}${DATADIR} \
		&& ${COPYTREE_SHARE} image ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
