# New ports collection makefile for:	JUMP Unified Mapping Platform
# Date created:				June 16 2004
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	jumpgis
PORTVERSION=	1.1.1
CATEGORIES=	graphics java
MASTER_SITES=	http://www.jump-project.org/downloads/jump/:main \
		http://sam.stral.net/freebsd/:extra
DISTFILES=	jump-${PORTVERSION}.zip:main \
		jump.png:extra jump.desktop:extra
EXTRACT_ONLY=	jump-${PORTVERSION}.zip

MAINTAINER=	boris@brooknet.com.au
COMMENT=	A GUI based application for viewing and processing spatial data

WRKSRC=		${WRKDIR}/jump
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
TARGET_DIR=	${PREFIX}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ZIP=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes
WANT_GNOME=	yes
PORTDOCS=	*

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
PLIST_SUB+=	GNOMELINKS=""
.else
PLIST_SUB+=	GNOMELINKS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,#!sh,#!/bin/sh,g" \
		-e "s,^set LIB=../lib,LIB=${TARGET_DIR}/lib,g"	\
		-e "s,workbench-properties.xml,~/.jump-workbench-properties.xml,g" \
		${WRKSRC}/bin/JUMPWorkbench-unix.sh

do-install:
	@${ECHO_CMD} "---> Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${TARGET_DIR}/lib
	${INSTALL_DATA} -d ${TARGET_DIR}/lib/ext
	@${ECHO_MSG} "Installing startup script"
	${INSTALL_SCRIPT} ${WRKSRC}/bin/JUMPWorkbench-unix.sh ${PREFIX}/bin/jumpgis

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "---> Installing documentation"
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.else
	@${ECHO_MSG} "---> Skipping documentation"
.endif

.if ${HAVE_GNOME:Mgnomelibs}!=""
	@${ECHO_MSG} "---> Installing GNOME application links"
	${INSTALL_DATA} ${DISTDIR}/jump.desktop ${X11BASE}/share/gnome/applications/
	${INSTALL_DATA} ${DISTDIR}/jump.png ${X11BASE}/share/gnome/pixmaps/
.endif

.include <bsd.port.post.mk>
