# $FreeBSD$

PORTNAME=	yaac
PORTVERSION=	1.0b89
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/yetanotheraprsc/
DISTNAME=	YAACSrc_20160321

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USES=		zip
USE_ANT=	yes
ALL_TARGET=	DISTRO
SUB_FILES=	yaac.sh

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/yaac

do-install:
	${UNZIP_NATIVE_CMD} -d ${STAGEDIR}/${JAVASHAREDIR}/${PORTNAME} ${WRKSRC}/YAAC.zip
	${RM} -rf ${STAGEDIR}/${JAVASHAREDIR}/${PORTNAME}/lib/rxtx-2.2pre2-bins
	${INSTALL_SCRIPT} ${WRKDIR}/yaac.sh ${STAGEDIR}${PREFIX}/bin/yaac

.include <bsd.port.mk>
