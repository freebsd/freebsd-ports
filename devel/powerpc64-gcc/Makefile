# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.1
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
		OPSYS=${OPSYS:tl}

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc
BUILD_DEPENDS=	${PKGNAMEPREFIX}${OPSYS:tl}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}${OPSYS:tl}-as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

WRKSRC=	${WRKDIR}/build-gcc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX}portbld-${OPSYS:tl}${OSREL} --disable-nls --enable-languages=c,c++ \
		--without-headers --disable-shared \
		--with-gmp=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--with-as=${LOCALBASE}/bin/${PKGNAMEPREFIX}${OPSYS:tl}-as \
		--with-ld=${LOCALBASE}/bin/${PKGNAMEPREFIX}${OPSYS:tl}-ld

CONFIGURE_SCRIPT=	../${PORTNAME}-${PORTVERSION}/configure

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

post-extract:
	@${MKDIR} ${WRKSRC}

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/info/*
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*

.include <bsd.port.mk>
