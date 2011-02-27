# New ports collection makefile for:	xmamegui
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	xmamegui
DISTVERSION=	0.9-1
PORTREVISION=	2
CATEGORIES=	emulators java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDLMAME frontend that has been written using Java

DEPRECATED=	development has ceased; try emulators/qmc2 instead
EXPIRATION_DATE=	2011-04-11

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_WRKSUBDIR=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

do-build:
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} 'exec ${JAVA} -jar ${DATADIR}/${PORTNAME}.jar "$$@"') \
	  > ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/XMAMEGUI.jar ${DATADIR}/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}/lib

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
