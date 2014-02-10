# $FreeBSD$

PORTNAME=	cryptix-jce
PORTVERSION=	20050328
PORTREVISION=	2
CATEGORIES=	java security
MASTER_SITES=	http://www.cryptix.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-snap

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JCE (Java Cryptography Extension) by Cryptix

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ZIP=	yes
NO_BUILD=	yes

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS 

.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-api.jar ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-compat.jar ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-provider.jar ${JAVAJARDIR}/
	${INSTALL_DATA} ${WRKDIR}/bin/${PORTNAME}-tests.jar ${JAVAJARDIR}/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.TXT ${DOCSDIR}/
	${INSTALL_DATA} ${WRKDIR}/LICENCE.TXT ${DOCSDIR}/
.endif

.include <bsd.port.mk>
