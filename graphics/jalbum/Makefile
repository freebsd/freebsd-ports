# New ports collection makefile for:	jalbum
# Date created:				20 March 2005
# Whom:					Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	jalbum
PORTVERSION=	1.5
CATEGORIES=	graphics java
MASTER_SITES=	ftp://ftp.i-scream.org/pub/jalbum.net/download/ \
		http://www.i-scream.org/pub/jalbum.net/download/
DISTNAME=	JAlbum-${PORTVERSION}

MAINTAINER=	tim@bishnet.net
COMMENT=	Web photo album generator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/JAlbum

USE_ZIP=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.3+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jalbum.sh

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${TAR} -cf - * | ${TAR} -xf - -C ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum.sh ${PREFIX}/bin/jalbum

.include <bsd.port.mk>
