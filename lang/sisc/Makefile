# New ports collection makefile for:	SISC
# Date created:				18 March 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	sisc
PORTVERSION=	1.7.9
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible Java-based Scheme interpreter

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.3+

EXTRACT_CMD=	${JAR}
EXTRACT_BEFORE_ARGS=	-xf

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|\(SISC_HOME=\).*$$|\1${JAVAJARDIR}|' \
		-e 's|^java|javavm|' ${WRKSRC}/dist/sisc.sh

do-build:
	cd ${WRKSRC}; ${SETENV} JAVA_HOME=${JAVA_HOME} ant sisc-lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.jar ${WRKSRC}/*.shp ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dist/sisc.sh ${PREFIX}/bin/sisc
	${MKDIR} ${DOCSDIR}
.for i in COPYING README
	${INSTALL_DATA} ${WRKSRC}/dist/${i} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
