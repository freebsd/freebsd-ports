# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	processing
PORTVERSION=	1.5.1
PORTEPOCH=	1
CATEGORIES=	graphics cad java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Programming environment for images, animation, and interactions

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	jikes>=1.22:java/jikes \
		${JAVA_HOME}/jre/lib/ext/RXTXcomm.jar:comms/rxtx

USES=		tar:tgz
USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	processing

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
	${RM} -r ${WRKSRC}/java
	${MV} ${WRKSRC}/processing ${WRKSRC}/start-processing
	${LN} -s ${JAVA_HOME} ${WRKSRC}/java
	${FIND} ${WRKSRC}/modes/java/reference/ -exec ${CHMOD} 555 {} \;

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/processing
	${CP} -Rp ${WRKSRC}/* ${STAGEDIR}${PREFIX}/libexec/processing
	${INSTALL_SCRIPT} ${WRKDIR}/processing ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
