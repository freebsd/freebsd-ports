PORTNAME=	openzfs
PORTVERSION=	2.3.4
PORTEPOCH=	1
CATEGORIES=	filesystems sysutils
MASTER_SITES=	https://github.com/openzfs/zfs/releases/download/zfs-${PORTVERSION}/
PKGNAMESUFFIX?=	-kmod
DISTNAME=	zfs-${DISTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenZFS kernel module for FreeBSD
WWW=		https://github.com/openzfs/zfs

LICENSE=	CDDL

USES=		cpe kmod
OPENZFS_TAGNAME=	1af41fd20
KMODTARGET?=	openzfs.ko

PLIST_FILES=	${KMODDIR}/${KMODTARGET}

OPTIONS_DEFINE=	DEBUG INVARIANTS GCOV
OPTIONS_DEFAULT=	DEBUG INVARIANTS
OPTIONS_SUB=	yes

GCOV_DESC=	Build kernel module with GCOV support (Requires gcc)

INVARIANTS_DESC=	Build kernel module with INVARIANTS
INVARIANTS_IMPLIES=	DEBUG

WRKSRC_SUBDIR=	module
MAKEFILE=	Makefile.bsd

.include <bsd.port.options.mk>

MAKE_OPTS+=	SYSDIR=${SRC_BASE}/sys

.if ${PORT_OPTIONS:MDEBUG}
MAKE_OPTS+=	WITH_DEBUG=true
PLIST_FILES+=	${KMODDIR}/${KMODTARGET}.debug
.endif

.if ${PORT_OPTIONS:MINVARIANTS}
MAKE_OPTS+=	WITH_INVARIANTS=true
.endif

.if ${PORT_OPTIONS:MGCOV}
USE_GCC=	yes
MAKE_OPTS+=	WITH_GCOV=true
.endif

ZFS_META_GITREV=	zfs-${PORTVERSION}-0-g${OPENZFS_TAGNAME}-dist
ZFS_META_RELEASE=	1
ZFS_META_VERSION=	${PORTVERSION}

post-patch:
	${ECHO} '#define ZFS_META_GITREV "${ZFS_META_GITREV}"' > ${WRKDIR}/${DISTNAME}/include/zfs_gitrev.h
	${ECHO} '#define ZFS_META_RELEASE "${ZFS_META_RELEASE}"' > ${WRKDIR}/${DISTNAME}/zfs_config.h
	${ECHO} '#define ZFS_META_VERSION "${ZFS_META_VERSION}"' >> ${WRKDIR}/${DISTNAME}/zfs_config.h

do-install:
	${INSTALL} ${WRKSRC}/openzfs.ko ${STAGEDIR}${KMODDIR}/${KMODTARGET}
.if ${PORT_OPTIONS:MDEBUG}
	${INSTALL} ${WRKSRC}/openzfs.ko.debug ${STAGEDIR}${KMODDIR}/${KMODTARGET}.debug
.endif

.include <bsd.port.mk>
