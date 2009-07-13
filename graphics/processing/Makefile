# New ports collection makefile for:	processing
# Date created:				20 June 2008
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	processing
PORTVERSION=	1.0.5
PORTEPOCH=		1
CATEGORIES=	graphics cad java
MASTER_SITES=	http://processing.org/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Programming environment for images, animation, and interactions

RUN_DEPENDS=	jikes>=1.22:${PORTSDIR}/java/jikes \
				${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:${PORTSDIR}/comms/rxtx

USE_JAVA=	1.6+
NO_BUILD=	yes

SUB_FILES=	processing

post-extract:
	${RM} -rf ${WRKSRC}/java
	${MV} ${WRKSRC}/processing ${WRKSRC}/start-processing
	${LN} -s ${JAVA_HOME} ${WRKSRC}/java
	${FIND} ${WRKSRC}/reference/ -exec ${CHMOD} 555 {} \;

do-install:
	${MKDIR} ${PREFIX}/libexec/processing
	${CP} -Rp ${WRKSRC}/* ${PREFIX}/libexec/processing
	${INSTALL_SCRIPT} ${WRKDIR}/processing ${PREFIX}/bin
.include <bsd.port.mk>
