# $FreeBSD$

PORTNAME=	faust
DISTVERSION=	1.4.20180118
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin architecture for the Faust programming language

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to link: can't create dynamic relocation R_AARCH64_ADR_PREL_PG_HI21 against symbol: vtable for LV2UI in readonly segment
.if ${/usr/bin/ld:L:tA} == /usr/bin/ld.lld
BROKEN_i386=		ld: error: can't create dynamic relocation R_386_32 against symbol: vtable for LV2UI in readonly segment
.endif

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		faust>0:audio/faust \
		${LOCALBASE}/include/boost/circular_buffer.hpp:devel/boost-libs

USES=		gmake localbase tar:bz2

BB_ACCOUNT=	agraef
BB_PROJECT=	faust-lv2
BB_COMMIT=	4dc83e28e998

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

LDFLAGS+=	-fPIC # recommended by 13i386 failure messages, it was only failing 

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD
OPTIONS_DEFAULT_i386=	SIMD

SIMD_CFLAGS=	-msse -msse2 -mfpmath=sse

.include <bsd.port.mk>
