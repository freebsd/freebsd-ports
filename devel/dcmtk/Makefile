# Created by: gahr
# $FreeBSD$

PORTNAME=	dcmtk
DISTVERSION=	3.6.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://dicom.offis.de/pub/dicom/offis/software/${PORTNAME}/${PORTNAME}${PORTVERSION:S/.//g}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit to work with DICOM objects

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		cmake:outsource jpeg
CMAKE_ARGS+=	-DDCMTK_WITH_DOXYGEN:BOOL=OFF \
		-DDCMTK_WITH_OPENSSL:BOOL=ON

SHLIBS=		dcmdata dcmdsig dcmimage dcmimgle dcmjpeg dcmnet \
		dcmpstat dcmqrdb dcmsr dcmtls dcmwlm ijg8 ijg12 \
		ijg16 i2d ofstd oflog charls dcmjpls

SHLIBVER=	${PORTVERSION:R:R}
PLIST_SUB=	SHLIBVER=${SHLIBVER}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

CFLAGS_amd64=	-fPIC

post-patch:
	${FIND} ${WRKSRC} -name "*.h.orig" -delete

post-patch-DOCS-off:
	${FIND} ${WRKSRC} -name CMakeLists.txt | ${XARGS} \
	    ${REINPLACE_CMD} -e '/INSTALL_DOCDIR/d'

post-install:
	${INSTALL_DATA} ${WRKSRC}/doxygen/manpages/man1/*.1 ${STAGEDIR}${PREFIX}/man/man1/
.for shlib in ${SHLIBS}
	@${MV} ${STAGEDIR}${PREFIX}/lib/lib${shlib}.so ${STAGEDIR}${PREFIX}/lib/lib${shlib}.so.${SHLIBVER}
	@${LN} -sf ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER} ${STAGEDIR}${PREFIX}/lib/lib${shlib}.so
.endfor

.include <bsd.port.mk>
