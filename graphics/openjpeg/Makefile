# New ports collection makefile for:	openjpeg
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	openjpeg
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openjpeg.org/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}

MAINTAINER=	trasz@freebsd.org
COMMENT=	An open-source JPEG 2000 codec

USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/OpenJPEG

PLIST_FILES=	include/openjpeg.h \
		lib/libopenjpeg.a \
		lib/libopenjpeg.so.${SHLIB_VER} \
		lib/libopenjpeg.so

SHLIB_VER=	1

do-install:
		${INSTALL_DATA} ${WRKSRC}/dist/openjpeg.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/dist/libopenjpeg.a ${PREFIX}/lib
		${INSTALL_PROGRAM} ${WRKSRC}/dist/libopenjpeg-1.0.0.so \
			${PREFIX}/lib/libopenjpeg.so.${SHLIB_VER}
		cd ${PREFIX}/lib && \
			${LN} -sf libopenjpeg.so.${SHLIB_VER} libopenjpeg.so

.include <bsd.port.mk>
