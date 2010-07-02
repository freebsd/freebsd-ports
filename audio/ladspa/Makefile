# New ports collection Makefile for: 	ladspa
# Date created:			11 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ladspa
PORTVERSION=	1.13
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	ladspa_sdk_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Linux Audio Developer's Simple Plugin API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/doc/COPYING

WRKSRC=		${WRKDIR}/ladspa_sdk
USE_GMAKE=	yes
USE_LDCONFIG=	yes
PROGRAM_FILES=	analyseplugin applyplugin listplugins
PLUGIN_FILES=	amp.so delay.so filter.so noise.so sine.so
PLUGIN_DIR?=	${PREFIX}/lib/ladspa/

post-patch:
	${REINPLACE_CMD} -e 's,-ldl,,; s,-O3,${CFLAGS},; \
		s,^CC,#CC,;s,^CPP,#CPP,;s,CPP,CXX,' ${WRKSRC}/src/makefile

do-build:
	cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${GMAKE} -f makefile targets

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
