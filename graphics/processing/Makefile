# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	processing
PORTVERSION=	1.5.1
PORTEPOCH=	1
CATEGORIES=	graphics cad java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux
EXTRACT_SUFX=	.tgz

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Programming environment for images, animation, and interactions

RUN_DEPENDS=	jikes>=1.22:${PORTSDIR}/java/jikes \
		${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:${PORTSDIR}/comms/rxtx

USE_JAVA=	1.6+
NO_BUILD=	yes

SUB_FILES=	processing

WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
post-extract:
	${RM} -rf ${WRKSRC}/java
	${MV} ${WRKSRC}/processing ${WRKSRC}/start-processing
	${LN} -s ${JAVA_HOME} ${WRKSRC}/java
	${FIND} ${WRKSRC}/modes/java/reference/ -exec ${CHMOD} 555 {} \;

do-install:
	${MKDIR} ${PREFIX}/libexec/processing
	${CP} -Rp ${WRKSRC}/* ${PREFIX}/libexec/processing
	${INSTALL_SCRIPT} ${WRKDIR}/processing ${PREFIX}/bin

.include <bsd.port.mk>
