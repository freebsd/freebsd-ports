# New ports collection makefile for:	fesi
# Date created:		5 August 2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	fesi
PORTVERSION=	1.1.5
CATEGORIES=	lang java
MASTER_SITES=	http://home.worldcom.ch/jmlugrin/fesi/
DISTNAME=	fesikit
EXTRACT_SUFX=	.zip

MAINTAINER=	leo@florida.sarang.net

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/javac:${PORTSDIR}/java/jdk11

NO_BUILD=	yes
USE_ZIP=	yes

JDK_VERSION=	1.1.8
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	@(cd ${WRKSRC} && find * -type d -exec ${CHMOD} 755 {} \;)

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes ${PREFIX}/share/java/fesi
	@${MKDIR} ${PREFIX}/share/java/fesi/docs ${PREFIX}/share/java/fesi/examples
	@(cd ${WRKSRC} && \
	 ${INSTALL_DATA} fesi.jar ${PREFIX}/share/java/classes; \
	 ${CP} [CR]* ${PREFIX}/share/java/fesi; \
	 ${CP} -R doc/html/* ${PREFIX}/share/java/fesi/docs; \
	 ${CP} -R examples/* ${PREFIX}/share/java/fesi/examples; \
	)
	@rmdir ${PREFIX}/share/java/fesi/examples/Fesi*/classes

.include <bsd.port.mk>
