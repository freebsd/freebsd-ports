# New ports collection makefile for:	openjpeg
# Date created:		2007-01-13
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	openjpeg
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openjpeg.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trasz
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An open-source JPEG 2000 codec

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

MAKE_JOBS_UNSAFE=	yes

USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/OpenJPEG_v1_3
JPWL_BINS=	JPWL_image_to_j2k JPWL_j2k_to_image
M2J_BINS=	extract_j2k_from_mj2 frames_to_mj2 mj2_to_frames wrap_j2k_in_mj2

PLIST_FILES=	include/openjpeg.h \
		lib/libopenjpeg.a \
		lib/libopenjpeg.so.${SHLIB_VER} \
		lib/libopenjpeg.so \
		${JPWL_BINS:S|^|bin/|} \
		${M2J_BINS:S|^|bin/|}

SHLIB_VER=	2

do-install:
		${INSTALL_DATA} ${WRKSRC}/libopenjpeg/openjpeg.h ${PREFIX}/include/
		${INSTALL_DATA} ${WRKSRC}/libopenjpeg.a ${PREFIX}/lib/
		${INSTALL_DATA} ${WRKSRC}/libopenjpeg-2.1.3.0.so \
			${PREFIX}/lib/libopenjpeg.so.${SHLIB_VER}
		cd ${PREFIX}/lib && \
			${LN} -sf libopenjpeg.so.${SHLIB_VER} libopenjpeg.so
.for file in ${M2J_BINS:S|^|mj2/|} ${JPWL_BINS:S|^|jpwl/|}
		${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
