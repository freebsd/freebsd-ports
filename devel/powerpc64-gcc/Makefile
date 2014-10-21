# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GCC
MASTER_SITE_SUBDIR=	releases/gcc-${DISTVERSION}
PKGNAMEPREFIX?=	powerpc64-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Cross GNU Compiler Collection for ${PKGNAMEPREFIX:C/-//g}

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

USES=	gmake iconv libtool tar:bzip2 makeinfo
PLIST_SUB=	TARGETARCH=${PKGNAMEPREFIX:C/-//g} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET}

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc
BUILD_DEPENDS=	${PKGNAMEPREFIX}${OPSYS:tl}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}${OPSYS:tl}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=	${WRKDIR}/build-gcc

.if empty(GCC_TARGET)
# We are building for a FreeBSD target
GCC_TARGET=	${PKGNAMEPREFIX}portbld-${OPSYS:tl}${OSREL}
BU_PREFIX=	${PKGNAMEPREFIX}${OPSYS:tl}
EXTRA_PATCHES+= ${FILESDIR}/freebsd-format-extensions
.else
BU_PREFIX=	${GCC_TARGET}
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${GCC_TARGET} --disable-nls --enable-languages=c,c++ \
		--without-headers \
		--with-gmp=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--with-as=${LOCALBASE}/bin/${BU_PREFIX}-as \
		--with-ld=${LOCALBASE}/bin/${BU_PREFIX}-ld

CONFIGURE_SCRIPT=	../${PORTNAME}-${PORTVERSION}/configure

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

post-extract:
	@${MKDIR} ${WRKSRC}

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/info/*
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*

.include <bsd.port.mk>
