# $FreeBSD$

PORTNAME=	yaac
PORTVERSION=	1.0b114
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/yetanotheraprsc/
DISTNAME=	YAACsrc_20170920

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Platform-independent Java application for the APRS network

BROKEN=		unfetchable

LICENSE=	LGPL3

BROKEN_armv7=	fails to package: yaac/build.xml:205: yaac/work/yaac/YAAC/site does not exist

USES=		zip
USE_ANT=	yes
USE_JAVA=	yes
ALL_TARGET=	DISTRO
SUB_FILES=	yaac.sh

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/yaac

do-install:
	${UNZIP_NATIVE_CMD} -d ${STAGEDIR}/${JAVASHAREDIR}/${PORTNAME} ${WRKSRC}/YAAC.zip
	${RM} -r ${STAGEDIR}/${JAVASHAREDIR}/${PORTNAME}/lib/rxtx-2.2pre2-bins
	${INSTALL_SCRIPT} ${WRKDIR}/yaac.sh ${STAGEDIR}${PREFIX}/bin/yaac

.include <bsd.port.mk>
