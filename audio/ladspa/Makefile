# New ports collection Makefile for: 	ladspa
# Date created:			11 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ladspa
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= arved

MAINTAINER=	arved@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
PROGRAM_FILES=	analyseplugin applyplugin listplugins
PLUGIN_FILES=	amp.so delay.so filter.so noise.so sine.so
PLUGIN_DIR?=	${PREFIX}/lib/ladspa/

post-patch:
	${REINPLACE_CMD} -e 's,-ldl,,' ${WRKSRC}/src/makefile

do-build:
	cd ${WRKSRC}/src; ${GMAKE} -f makefile targets

do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/ladspa.h ${PREFIX}/include
.for file in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PLUGIN_DIR}
.for file in ${PLUGIN_FILES}
	@${INSTALL_DATA} ${WRKSRC}/plugins/${file} ${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
