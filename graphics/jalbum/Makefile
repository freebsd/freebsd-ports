# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	jalbum
PORTVERSION=	10.10.7
CATEGORIES=	graphics java
MASTER_SITES=	http://jalbum.net/download/
DISTNAME=	jAlbum${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Web photo album generator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/jAlbum

USES=		zip
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jalbum.sh

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${TAR} -cf - * | ${TAR} -xf - -C ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum.sh ${PREFIX}/bin/jalbum

.include <bsd.port.mk>
