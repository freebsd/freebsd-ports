# Created by: Glenn Johnson
# $FreeBSD$

PORTNAME=	libimg
PORTVERSION=	1.2.4
PORTREVISION=	9
CATEGORIES?=	graphics tk
MASTER_SITES=	SF/tkimg/tkimg/${PORTVERSION:R}
DISTNAME=	img${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A library of image format handlers for Tk4.1 and later

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff

DIR=		lib/Img1.2

SHLIB_NAME=	libimg.so.1
SHLIB_LINK=	${SHLIB_NAME:R}

PLIST_SUB+=	DIR="${DIR}" SHLIB_NAME="${SHLIB_NAME}" \
		SHLIB_LINK="${SHLIB_LINK}"

WRKSRC=		${WRKDIR}/img${PORTVERSION}
MAKEFILE=	${FILESDIR}/Makefile.bsd
USES=		tk
MAKE_ENV+=	TCL_VER=${TCL_VER}

# We don't need the bundled libraries:
EXTRACT_AFTER_ARGS=	--exclude '*/libz/*' \
		--exclude '*/compat/*' --exclude '*/libtiff/*' \
		--exclude '*/libjpeg/*' --exclude '*/libpng/*'

MAKE_ARGS=	PORTVERSION="${PORTVERSION}" LOCALBASE="${LOCALBASE}" \
		MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}" \
		SHLIB_NAME="${SHLIB_NAME}" \
		DIR="${DIR}"

USE_LDCONFIG=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${TCL_VER} == 8.4
PKGNAMESUFFIX=	-tk84
EXTRA_PATCHES=	${FILESDIR}/tk84-Tk_PhotoPutBlock ${FILESDIR}/tk84-warnings
CONFLICTS=	libimg-tkstep-1.*
.else
EXTRA_PATCHES=	${FILESDIR}/tk85-Tk_PhotoPutBlock ${FILESDIR}/tk84-warnings
CONFLICTS=	libimg-tk84-1.* libimg-tkstep-1.*
.endif

.include <bsd.port.post.mk>
