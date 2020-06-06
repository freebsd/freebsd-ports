# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

OCBM_VERSION=	0.4.99.99a
DISTVERSIONPREFIX=	v
DIST_SUBDIR=	opencbm
DISTINFO_FILE=	${.CURDIR}/../opencbm/distinfo

PATCH_DIST_STRIP=	-p1
PATCH_SITES=	https://github.com/OpenCBM/OpenCBM/commit/

USE_GITHUB=	yes
GH_ACCOUNT=	OpenCBM
GH_PROJECT=	OpenCBM

PATCHDIR=	${.CURDIR}/../opencbm/files
PATCH_WRKSRC=	${WRKDIR}/OpenCBM-${OCBM_VERSION}

MAKE_ENV=	USER_CFLAGS="${CFLAGS}"

OCBM_LIBVERSION=	0.4.99.99
PLUGINBASENAME=	${PREFIX}/lib/opencbm/plugin/libopencbm-
