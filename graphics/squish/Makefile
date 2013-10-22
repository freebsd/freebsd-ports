# Created by: Reinier de Blois <me@rdb.name>
# $FreeBSD$

PORTNAME=	squish
PORTVERSION=	1.10
CATEGORIES=	graphics
MASTER_SITES=	http://libsquish.googlecode.com/files/

MAINTAINER=	me@rdb.name
COMMENT=	Open source DXT compression library

LICENSE=	MIT

USES=		gmake
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX}
PLIST_FILES=	include/squish.h \
		lib/libsquish.a
CXXFLAGS+=	-fPIC

OPTIONS_RADIO=	RG1
OPTIONS_RADIO_RG1=	ALTIVEC SSE
ALTIVEC_DESC=	Use Altivec instructions
RG1_DESC=	Optimizations Selection

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALTIVEC}
CXXFLAGS+=	-DSQUISH_USE_ALTIVEC=1 -maltivec
.endif

.if ${PORT_OPTIONS:MSSE}
CXXFLAGS+=	-DSQUISH_USE_SSE=2 -msse
.endif

.include <bsd.port.mk>
