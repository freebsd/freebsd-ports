# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysroot
PORTVERSION=	1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${PUB_FREEBSD}/releases/arm64/aarch64/11.3-RELEASE/
PKGNAMEPREFIX=	gnatcross-
PKGNAMESUFFIX=	-aarch64
DISTNAME=	base
DIST_SUBDIR=	gnatcross/arm64-aarch64/R11_3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeBSD sysroots for C/Ada cross-compiler (${ARCH})

# avoid aarch64 x aarch64
ONLY_FOR_ARCHS=		amd64 i386

USES=		tar:txz

NO_BUILD=	yes
NO_MTREE=	yes

PUB_FREEBSD=	ftp://ftp.freebsd.org/pub/FreeBSD
PREFIX=		${LOCALBASE}/FreeBSD_ARM64

EXTRACT_AFTER_ARGS=	lib/ usr/include/ usr/lib/

post-extract:
	/bin/chflags -R noschg ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/sysroot
	@${MV} ${WRKDIR}/lib ${STAGEDIR}${PREFIX}/sysroot
	@${MV} ${WRKDIR}/usr ${STAGEDIR}${PREFIX}/sysroot
	@${ECHO_CMD} aarch64-aux-freebsd11.3 > ${STAGEDIR}${PREFIX}/sysroot/target_triplet
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} sysroot -type d -empty -delete)
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} sysroot \( -type f -or -type l \) \
		| ${SORT} >> ${TMPPLIST})

.include <bsd.port.mk>
