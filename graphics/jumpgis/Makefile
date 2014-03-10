# Created by: Sam Lawrance <boris@brooknet.com.au>
# $FreeBSD$

PORTNAME=	jumpgis
PORTVERSION=	1.1.2
PORTREVISION=	5
CATEGORIES=	graphics java geography
MASTER_SITES=	http://www.jump-project.org/downloads/jump/:main \
		http://T32.TecNik93.com/FreeBSD/others_ports/${PORTNAME}/sources/:main,extra
DISTFILES=	jump-${PORTVERSION}.zip:main \
		jump.png:extra jump.desktop:main,extra
EXTRACT_ONLY=	jump-${PORTVERSION}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI based application for viewing and processing spatial data

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

WRKSRC=		${WRKDIR}/jump
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
TARGET_DIR=	${PREFIX}/${PORTNAME}

USES=		zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
PORTDOCS=	*

REINPLACE_ARGS=	-i ""

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,#!sh,#!/bin/sh,g" \
		-e "s,^LIB=../lib,LIB=${TARGET_DIR}/lib,g"	\
		-e "s,workbench-properties.xml,~/.jump-workbench-properties.xml,g" \
		${WRKSRC}/bin/JUMPWorkbench-unix.sh

do-install:
	@${ECHO_CMD} "---> Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${TARGET_DIR}/lib
	${MKDIR} ${TARGET_DIR}/lib/ext
	@${ECHO_MSG} "Installing startup script"
	${INSTALL_SCRIPT} ${WRKSRC}/bin/JUMPWorkbench-unix.sh ${PREFIX}/bin/jumpgis

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "---> Installing documentation"
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.else
	@${ECHO_MSG} "---> Skipping documentation"
.endif

.include <bsd.port.post.mk>
