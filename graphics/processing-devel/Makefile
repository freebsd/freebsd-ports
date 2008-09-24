# New ports collection makefile for:	processing
# Date created:				20 June 2008
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	processing-devel
PORTVERSION=	0142
PORTREVISION=	1
CATEGORIES=	graphics cad java
MASTER_SITES=	http://processing.org./download/
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Open source programming language and environment for people who want to program images, animation, and interactions

RUN_DEPENDS=	jikes:${PORTSDIR}/java/jikes \
		${LOCALBASE}/lib/jre/RXTXcomm.jar:${PORTSDIR}/comms/rxtx

USE_JAVA=	1.5+
NO_BUILD=	yes

post-extract:
	# Go from 124 Mb to 73 Mb
	${RM} -rf ${WRKSRC}/java/.systemPrefs
	${RM} -rf ${WRKSRC}/java/[a-km-z]*
	${RM} -rf ${WRKSRC}/java/[A-Z]*
	${RM} -rf ${WRKSRC}/java/lib/[a-qsu-z]*

	${FIND} ${WRKSRC}/reference -type f -exec ${CHMOD} go-xw {} \;

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/processing
	${RM} ${WRKSRC}/processing.*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/processing ${PREFIX}/bin/processing-devel
	${MKDIR} ${PREFIX}/libexec/processing-devel
	${CP} -Rp ${WRKSRC}/* ${PREFIX}/libexec/processing-devel

.include <bsd.port.mk>
