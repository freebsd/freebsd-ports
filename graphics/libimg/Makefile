# New ports collection makefile for:	img
# Date Created:		20 February 1999
# Whom:			Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	libimg
PORTVERSION=	1.2.4
PORTREVISION=	5
CATEGORIES?=	graphics tk
MASTER_SITES=	SF/tkimg
DISTNAME=	img${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of image format handlers for Tk4.1 and later

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff

.if defined(USE_TK) && ${USE_TK} == 83
PKGNAMESUFFIX=	-tk83
USE_TK=		83
USE_TK_BUILD=	83
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV+=	TCL_VER=8.3
PATCHDIR=
EXTRA_PATCHES=	${FILESDIR}/pre-tk84-warnings
CONFLICTS=	libimg-1.* libimg-tkstep-1.*
.else
USE_TK=		84
USE_TK_BUILD=	84
MAKEFILE=	${FILESDIR}/Makefile.bsd
EXTRA_PATCHES=	${FILESDIR}/tk84-Tk_PhotoPutBlock ${FILESDIR}/tk84-warnings
CONFLICTS=	libimg-tk83-1.* libimg-tkstep-1.*
.endif

DIR=		lib/Img1.2

SHLIB_NAME=	libimg.so.1
SHLIB_LINK=	${SHLIB_NAME:R}

PLIST_SUB+=	DIR="${DIR}" SHLIB_NAME="${SHLIB_NAME}" \
		SHLIB_LINK="${SHLIB_LINK}"

WRKSRC=		${WRKDIR}/img${PORTVERSION}

# We don't need the bundled libraries:
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude '*/libz/*' \
		--exclude '*/compat/*' --exclude '*/libtiff/*' \
		--exclude '*/libjpeg/*' --exclude '*/libpng/*'

MAKE_ARGS=	PORTVERSION="${PORTVERSION}" LOCALBASE="${LOCALBASE}" \
		MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}" \
		SHLIB_NAME="${SHLIB_NAME}" \
		DIR="${DIR}"

USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
