# Created by: gahr
# $FreeBSD$

PORTNAME=	dcmtk
DISTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://dicom.offis.de/pub/dicom/offis/software/${PORTNAME}/${PORTNAME}${PORTVERSION:S/.//g}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A toolkit to work with DICOM files

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
    		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USES=		cmake:outsource
CMAKE_ARGS+=	-DDCMTK_WITH_DOXYGEN:BOOL=OFF

SHLIBS=		dcmdata dcmdsig dcmimage dcmimgle dcmjpeg dcmnet \
		dcmpstat dcmqrdb dcmsr dcmtls dcmwlm ijg8 ijg12 \
		ijg16 i2d ofstd oflog charls dcmjpls

SHLIBVER=	${PORTVERSION:R:R}
PLIST_SUB=	SHLIBVER=${SHLIBVER}

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${FIND} ${WRKSRC} -name "*.h.orig" -delete
.if !${PORT_OPTIONS:MDOCS}
	${FIND} ${WRKSRC} -name CMakeLists.txt | ${XARGS} \
	    ${REINPLACE_CMD} -e '/INSTALL_DOCDIR/d'
.endif

post-install:
.for shlib in ${SHLIBS}
	@${MV} ${PREFIX}/lib/lib${shlib}.so ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER}
	@${LN} -sf ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER} ${PREFIX}/lib/lib${shlib}.so
.endfor

#.include "Makefile.man"
.include <bsd.port.post.mk>
