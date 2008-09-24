# New ports collection makefile for:	processing
# Date created:				20 June 2008
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	processing
PORTVERSION=	0135
PORTREVISION=	1
CATEGORIES=	graphics cad java
MASTER_SITES=	http://processing.org./download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Open source programming language and environment for people who want to program images, animation, and interactions

RUN_DEPENDS=	jikes:${PORTSDIR}/java/jikes \
		${JAVA_HOME}/jre/RXTXcomm.jar:${PORTSDIR}/comms/rxtx

USE_JAVA=	1.5+
NO_BUILD=	yes

post-extract:
	# Go from 116 Mb to 28 Mb
	${RM} -rf ${WRKSRC}/jikes
	${RM} -rf ${WRKSRC}/java

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/processing
	${RM} ${WRKSRC}/processing.*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/processing ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/processing
	${CP} -Rp ${WRKSRC}/* ${PREFIX}/libexec/processing

.include <bsd.port.mk>
