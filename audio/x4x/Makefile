# New ports collection makefile for:	x4x
# Date created:				09 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	x4x
PORTVERSION=	0.1.2
CATEGORIES=	audio java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alex@foxybanana.com
COMMENT=	X4X for XMMS2

BUILD_DEPENDS=	${JAVALIBDIR}/xmms2java.jar:${PORTSDIR}/audio/java-xmms2 \
		${JAVALIBDIR}/swt.jar:${PORTSDIR}/x11-toolkits/swt31 \
		${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j \
		${JAVALIBDIR}/jcifs.jar:${PORTSDIR}/net/jcifs \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom \
		${JAVALIBDIR}/jid3lib.jar:${PORTSDIR}/audio/jid3lib

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
MAKE_ARGS=	-DswtHome=$J{JAVALIBDIR} \
		-Dprefix=${JAVASHAREDIR} \
		-Dswt=${JAVALIBDIR}/swt.jar \
		-Dxmms2java=${JAVALIBDIR}/xmms2java.jar \
		-Dlog4j=${JAVALIBDIR}/log4j.jar \
		-Djcifs=${JAVALIBDIR}/jcifs.jar \
		-Djunit=${JAVALIBDIR}/junit.jar \
		-Djdom=${JAVALIBDIR}/jdom.jar \
		-Djid3lib=${JAVALIBDIR}/jid3lib.jar

USE_BZIP2=	yes
WRKSRC=	${WRKDIR}/X4X
DATADIR=	${JAVASHAREDIR}/X4X

do-run:
	cd ${WRKSRC} && ant ${MAKE_ARGS} run

pre-install:
	${REINPLACE_CMD} -e \
	's|$${prefix}/share/X4X/images|$${prefix}/X4X/images|g' \
	${WRKSRC}/build.xml
	${REINPLACE_CMD} -e 's|$${prefix}/bin/X4X|${PREFIX}/bin/X4X|g' \
	${WRKSRC}/build.xml

do-install:
	@cd ${WRKSRC} && ant ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
