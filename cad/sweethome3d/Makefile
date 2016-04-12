# Created by: Matthias Petermann <matthias@petermann-it.de>
# $FreeBSD$

PORTNAME=	sweethome3d
PORTVERSION=	5.2
CATEGORIES=	cad java
MASTER_SITES=	SF/${PORTNAME}/SweetHome3D-source/${DISTNAME}/
DISTNAME=	SweetHome3D-${PORTVERSION}-src

MAINTAINER=	matthias@petermann-it.de
COMMENT=	Free interior design application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

BUILD_DEPENDS=	java3d>=0:java/java3d
RUN_DEPENDS=	java3d>=0:java/java3d

USES=		zip
NO_ARCH=	yes
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

ALL_TARGET=	jarExecutable
JARNAME=	SweetHome3D-${PORTVERSION}.jar

SUB_FILES=	sweethome3d.sh
SUB_LIST=	JARNAME=${JARNAME}

PLIST_FILES=	bin/sweethome3d \
		%%JAVAJARDIR%%/${JARNAME} \
		share/pixmaps/sweethome3d-icon.png

DESKTOP_ENTRIES="Sweet Home 3D" "" "${PORTNAME}-icon" "${PORTNAME}" "" ${FALSE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/install/${JARNAME} ${STAGEDIR}${JAVAJARDIR}/${JARNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/sweethome3d.sh ${STAGEDIR}${PREFIX}/bin/sweethome3d
	${INSTALL_DATA} ${WRKSRC}/deploy/SweetHome3DIcon32x32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/sweethome3d-icon.png

.include <bsd.port.mk>
