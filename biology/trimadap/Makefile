PORTNAME=	trimadap
DISTVERSION=	0.1-3
DISTVERSIONSUFFIX=	-gddfef21
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Trim adapter sequences from Illumina data using heuristic rules
WWW=		https://github.com/lh3/trimadap

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	uses hard-coded SSE instructions

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/trimadap-mt

CFLAGS_i386=	-msse2
CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimadap-mt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
