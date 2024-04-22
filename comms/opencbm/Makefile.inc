OCBM_VERSION=	0.4.99.104
OCBM_REVISION=	2
DISTVERSIONPREFIX=	v
DISTINFO_FILE=	${.CURDIR}/../opencbm/distinfo

USE_GITHUB=	yes
GH_ACCOUNT=	OpenCBM
GH_PROJECT=	OpenCBM

MAKEFILE?=	LINUX/Makefile
MAKE_ARGS=	CC="${CC}" \
		INFODIR=${PREFIX}/${INFO_PATH} \
		MANDIR=${PREFIX}/share/man/man1 \
		SUBDIRS_PLUGIN_XA1541=opencbm/lib/plugin/xa1541
MAKE_ENV=	USER_CFLAGS="${CFLAGS}"

PLIST_SUB=	OCBM_VERSION=${OCBM_VERSION}

PORTSCOUT=	limit:^v\d

PLUGINBASENAME=	${PREFIX}/lib/opencbm/plugin/libopencbm-

.if ${PORTNAME:Nopencbm-kmod}
.  if defined(PORTREVISION)
IGNORE=		PORTREVISION must not be defined explicitly
.  else
PORTREVISION=	${OCBM_REVISION}
.  endif
.endif
