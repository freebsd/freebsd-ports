# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpsprune
PORTVERSION=	15.1
CATEGORIES=	astro java
MASTER_SITES=	http://activityworkshop.net/software/${PORTNAME}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Application for viewing, editing, and converting GPS coordinate data

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+

SUB_FILES=	gpsprune.sh
SUB_LIST=	JARNAME=${DISTNAME}

PLIST_FILES=	bin/gpsprune ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

OPTIONS_DEFINE=	JAVA3D
JAVA3D_DESC=	Support for 3D view of track

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAVA3D}
RUN_DEPENDS+=	java3d>=1.5.2:${PORTSDIR}/java/java3d
.endif

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/gpsprune.sh ${STAGEDIR}${PREFIX}/bin/gpsprune

.include <bsd.port.mk>
