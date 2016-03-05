# Created by: Gleb Smirnoff <glebius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osmosis
PORTVERSION=	0.43.1
CATEGORIES=	astro java
MASTER_SITES=	http://bretth.dev.openstreetmap.org/osmosis-build/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line Java app for processing OpenStreetMap data

USES=		tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}

USE_JAVA=	yes
JAVA_VERSION=	1.6+

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|^\(MYAPP_HOME=\).*|\1${DATADIR}|' ${WRKSRC}/bin/osmosis

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "script config lib" ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/osmosis ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
