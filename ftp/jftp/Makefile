# ex:ts=8
# Ports collection makefile for:	jftp
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jftp
PORTVERSION=	1.45
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	j-ftp
DISTNAME=	j-ftp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Network Browser

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/j-ftp
USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	yes
SUB_FILES=	jftp.sh
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	bin/jftp %%DATADIR%%/jftp.jar
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jftp.sh ${PREFIX}/bin/jftp
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/jars/jftp.jar ${DATADIR}

.include <bsd.port.mk>
