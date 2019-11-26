# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jiic
PORTVERSION=	20120110
CATEGORIES=	devel multimedia java
MASTER_SITES=	LOCAL/ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Streaming-based Java implementation of ISO 9660

LICENSE=	LGPL21

BUILD_DEPENDS=	${JAVALIBDIR}/sabre.jar:devel/sabre
RUN_DEPENDS=	${JAVALIBDIR}/sabre.jar:devel/sabre

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_JAVA=	yes
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/iso9660.jar

post-extract:
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/iso9660.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/iso9660.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
