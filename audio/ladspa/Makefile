# New ports collection Makefile for: 	ladspa
# Date created:			11 May 2002
# Whom:				Tilman Linneweh <freebsdports@arved.de
#
# $FreeBSD$

PORTNAME=	ladspa
PORTVERSION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	ladspa_sdk
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsdports@arved.de

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile
ALL_TARGET=	targets

PROGRAM_FILES=	analyseplugin applyplugin listplugins
PLUGIN_FILES=	amp.so delay.so filter.so noise.so sine.so
PLUGIN_DIR=	${PREFIX}/lib/ladspa/

do-install:
	@${INSTALL_DATA} ${WRKSRC}/ladspa.h ${PREFIX}/include
.for file in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/../bin/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PLUGIN_DIR}
.for file in ${PLUGIN_FILES}
	@${INSTALL_DATA} ${WRKSRC}/../plugins/${file} ${PLUGIN_DIR}
.endfor

.include <bsd.port.mk>
