PORTNAME=	amazon-efs-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	filesystems python

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Amazon EFS mount helper and watchdog utilities
WWW=		https://github.com/aws/efs-utils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	aws-lc-fips-sys (FIPS static build via s2n-tls) supports only x86_64 and aarch64 on BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>0:devel/py-botocore@${PY_FLAVOR}

USES=		cargo gmake go:no_targets llvm python:3.8+,run shebangfix
USE_PYTHON=	noflavors
USE_RC_SUBR=	amazon-efs-mount-watchdog

SHEBANG_FILES=	src/mount_efs/__init__.py \
		src/watchdog/__init__.py

MAKE_ENV+=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_PROJECT=	efs-utils

CARGO_SRC_SUBDIR=	src/proxy
CARGO_VENDOR_DIR=	${CARGO_WRKSRC}/cargo-crates
CARGO_BUILD=	yes
CARGO_INSTALL=	no
CARGO_TEST=	no

EFS_SBINDIR=	${PREFIX}/sbin
EFS_LIBDIR=	${PREFIX}/lib/amazon/efs
EFS_CONFDIR=	${PREFIX}/etc/amazon/efs

post-patch:
	@${REINPLACE_CMD} 's|/etc/amazon/efs|${EFS_CONFDIR}|g' \
		${WRKSRC}/src/efs_utils_common/constants.py \
		${WRKSRC}/src/watchdog/__init__.py \
		${WRKSRC}/dist/efs-utils.conf \
		${WRKSRC}/dist/s3files-utils.conf \
		${WRKSRC}/man/mount.efs.8 \
		${WRKSRC}/man/mount.s3files.8
	@${REINPLACE_CMD} -e 's|mount\.efs|mount_efs|g' \
		${WRKSRC}/src/efs_utils_common/file_utils.py \
		${WRKSRC}/man/mount.efs.8

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/efs-proxy \
		${STAGEDIR}${EFS_SBINDIR}/efs-proxy
	${INSTALL_SCRIPT} ${WRKSRC}/src/mount_efs/__init__.py \
		${STAGEDIR}${EFS_SBINDIR}/mount_efs
	${INSTALL_SCRIPT} ${WRKSRC}/src/watchdog/__init__.py \
		${STAGEDIR}${EFS_SBINDIR}/amazon-efs-mount-watchdog
	${MKDIR} ${STAGEDIR}${EFS_LIBDIR}/efs_utils_common
	${INSTALL_DATA} ${WRKSRC}/src/efs_utils_common/*.py \
		${STAGEDIR}${EFS_LIBDIR}/efs_utils_common/
	${MKDIR} ${STAGEDIR}${EFS_LIBDIR}/mount_efs
	${INSTALL_DATA} ${WRKSRC}/src/mount_efs/*.py \
		${STAGEDIR}${EFS_LIBDIR}/mount_efs/
	${MKDIR} ${STAGEDIR}${EFS_LIBDIR}/mount_s3files
	${INSTALL_DATA} ${WRKSRC}/src/mount_s3files/*.py \
		${STAGEDIR}${EFS_LIBDIR}/mount_s3files/
	${MKDIR} ${STAGEDIR}${EFS_CONFDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/efs-utils.conf \
		${STAGEDIR}${EFS_CONFDIR}/efs-utils.conf.sample
	${INSTALL_DATA} ${WRKSRC}/dist/s3files-utils.conf \
		${STAGEDIR}${EFS_CONFDIR}/s3files-utils.conf.sample
	${INSTALL_DATA} ${WRKSRC}/dist/efs-utils.crt \
		${STAGEDIR}${EFS_CONFDIR}/efs-utils.crt
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/mount.efs.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/mount_efs.8

post-install:
	${MKDIR} ${STAGEDIR}/var/log/amazon/efs
	${MKDIR} ${STAGEDIR}/var/run/efs

.include <bsd.port.mk>
