PORTNAME=	trimadap
DISTVERSION=	0.1-3
DISTVERSIONSUFFIX=	-gddfef21
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapter sequences from Illumina data using heuristic rules

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses hard-coded SSE instructions

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/trimadap-mt

CFLAGS_i386=	-msse2

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64le
CFLAGS+=	-DNO_WARN_X86_INTRINSICS
USES=		compiler:gcc-c++11-lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
