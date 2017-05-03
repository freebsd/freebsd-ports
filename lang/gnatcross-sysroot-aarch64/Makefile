# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysroot
PORTVERSION=	1
CATEGORIES=	lang
MASTER_SITES=	${PUB_FREEBSD}/releases/arm64/aarch64/11.0-RELEASE/:R11
PKGNAMEPREFIX=	gnatcross-
PKGNAMESUFFIX=	-aarch64
DIST_SUBDIR=	gnatcross/arm64-aarch64/${RELEASE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD sysroots for C/Ada cross-compiler (${ARCH})

NO_BUILD=	yes
NO_MTREE=	yes

PUB_FREEBSD=	ftp://ftp.freebsd.org/pub/FreeBSD
PREFIX=		${LOCALBASE}/FreeBSD_ARM64

ONLY_FOR_ARCHS=		i386 amd64	# avoid aarch64 x aarch64
EXTRACT_AFTER_ARGS=	lib/ usr/include/ usr/lib/

OPTIONS_SINGLE=		SG1
OPTIONS_SINGLE_SG1=	RELEASE_11_0
OPTIONS_DEFAULT=	RELEASE_11_0

RELEASE_11_0_DESC=	FreeBSD 11.0 Release
RELEASE_11_0_DISTFILES=	base.txz:R11
RELEASE_11_0_VARS=	RELEASE=R11_0 CTARGET=aarch64-aux-freebsd11.0

post-extract:
	/bin/chflags -R noschg ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sysroot
	@${MV} ${WRKDIR}/lib ${STAGEDIR}${PREFIX}/sysroot
	@${MV} ${WRKDIR}/usr ${STAGEDIR}${PREFIX}/sysroot
	@echo ${CTARGET} > ${STAGEDIR}${PREFIX}/sysroot/target_triplet
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} sysroot -type d -empty -delete)
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} sysroot \( -type f -or -type l \) \
		| ${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
