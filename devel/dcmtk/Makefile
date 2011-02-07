# New ports collection Makefile for:	dcmtk
# Date created:				26 July 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	dcmtk
DISTVERSION=	3.6.0
CATEGORIES=	devel
MASTER_SITES=	ftp://dicom.offis.de/pub/dicom/offis/software/${PORTNAME}/${PORTNAME}${PORTVERSION:S/.//g}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A toolkit to work with DICOM files

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
    		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes

SHLIBS=		dcmdata dcmdsig dcmimage dcmimgle dcmjpeg dcmnet \
		dcmpstat dcmqrdb dcmsr dcmtls dcmwlm ijg8 ijg12 \
		ijg16 i2d ofstd oflog charls dcmjpls

SHLIBVER=	${PORTVERSION:R:R}
PLIST_SUB=	SHLIBVER=${SHLIBVER}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-install:
.for shlib in ${SHLIBS}
	@${MV} ${PREFIX}/lib/lib${shlib}.so ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER}
	@${LN} -sf ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER} ${PREFIX}/lib/lib${shlib}.so
.endfor

#.include "Makefile.man"
.include <bsd.port.post.mk>
