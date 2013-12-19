# Created by: Reinier de Blois <rddeblois@gmail.com>
# $FreeBSD$

PORTNAME=	squish
PORTVERSION=	1.10
CATEGORIES=	graphics
MASTER_SITES=	http://libsquish.googlecode.com/files/

MAINTAINER=	rddeblois@gmail.com
COMMENT=	Open source DXT compression library

LICENSE=	MIT

USES=		gmake
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX}
PLIST_FILES=	include/squish.h \
		lib/libsquish.a
CXXFLAGS+=	-fPIC -include limits.h

OPTIONS_RADIO=	RG1
OPTIONS_RADIO_RG1=	ALTIVEC SSE
ALTIVEC_DESC=	Use Altivec instructions
RG1_DESC=	Optimizations Selection

ALTIVEC_CXXFLAGS=	-DSQUISH_USE_ALTIVEC=1 -maltivec
SSE_CXXFLAGS=		-DSQUISH_USE_SSE=2 -msse

.include <bsd.port.mk>
