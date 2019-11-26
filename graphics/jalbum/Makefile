# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	jalbum
PORTVERSION=	10.10.7
CATEGORIES=	graphics java
MASTER_SITES=	http://jalbum.net/download/
DISTNAME=	jAlbum${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Web photo album generator

WRKSRC=		${WRKDIR}/jAlbum

USES=		zip
NO_BUILD=	yes

USE_JAVA=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	jalbum.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${TAR} -cf - * | ${TAR} -xf - -C ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jalbum.sh ${STAGEDIR}${PREFIX}/bin/jalbum

.include <bsd.port.mk>
