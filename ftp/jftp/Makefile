# Created by: ijliao
# $FreeBSD$

PORTNAME=	jftp
PORTVERSION=	1.60
CATEGORIES=	ftp java
MASTER_SITES=	SF/j-ftp/${PORTNAME}/${PORTVERSION}
DISTNAME=	j-ftp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Network Browser

LICENSE=	GPLv2

NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/j-ftp

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_FILES=	bin/jftp %%DATADIR%%/jftp.jar
SUB_FILES=	jftp.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jftp.sh ${STAGEDIR}${PREFIX}/bin/jftp
	${INSTALL_DATA} ${WRKSRC}/build/jars/jftp.jar ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
