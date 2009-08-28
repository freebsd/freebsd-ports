# ex:ts=8
# Ports collection makefile for:	dmachine
# Date Created:			Dec 15, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dmachine
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	ftp java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A non interactive, non graphical, batch download manager

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	dmachine
MAKE_ARGS=	JAVAC="${JAVAC}"
SUB_FILES=	dmachine.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dmachine.sh ${PREFIX}/bin/dmachine
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.class ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../dmachine.cnf ${DOCSDIR}
.endif

.include <bsd.port.mk>
