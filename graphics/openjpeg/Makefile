# New ports collection makefile for:	openjpeg
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	openjpeg
PORTVERSION=	1.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.openjpeg.org/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	An open-source JPEG 2000 codec

USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/trunk

PLIST_FILES=	include/openjpeg.h \
		lib/libopenjpeg.a \
		lib/libopenjpeg.so.${SHLIB_VER} \
		lib/libopenjpeg.so

SHLIB_VER=	2

do-install:
		${INSTALL_DATA} ${WRKSRC}/libopenjpeg/openjpeg.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/libopenjpeg.a ${PREFIX}/lib
		${INSTALL_PROGRAM} ${WRKSRC}/libopenjpeg-2.1.2.0.so \
			${PREFIX}/lib/libopenjpeg.so.${SHLIB_VER}
		cd ${PREFIX}/lib && \
			${LN} -sf libopenjpeg.so.${SHLIB_VER} libopenjpeg.so

.include <bsd.port.mk>
