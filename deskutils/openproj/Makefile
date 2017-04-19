# $FreeBSD$

PORTNAME=	openproj
PORTVERSION=	1.4
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/OpenProj%20Binaries/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, open source Project Manager

DEPRECATED=	Development ceased, superseded by deskutils/projectlibre
EXPIRATION_DATE=	2017-05-19

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DATAFILES=	lib license openproj.jar readme.html

SUB_FILES=	openproj.sh

do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/openproj.sh ${STAGEDIR}${PREFIX}/bin/openproj

.include <bsd.port.mk>
