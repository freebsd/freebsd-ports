PORTNAME=	gmap
PORTVERSION=	2025.07.31
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
DISTNAME=	${PORTNAME}-gsnap-${PORTVERSION:C|\.|-|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences
WWW=		https://github.com/genentech/gmap-gsnap \
		http://research-pub.gene.com/gmap/

LICENSE=	GMAP
LICENSE_NAME=	GMAP License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=		aarch64 amd64 i386 powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	untested on other architectures

USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_have_decl___builtin_popcount=yes \
		ac_cv_have_decl___builtin_clz=yes \
		ac_cv_have_decl___builtin_ctz=yes \
		ac_cv_have_decl___builtin_clzll=yes \
		ac_cv_have_decl___builtin_ctzll=yes

CONFLICTS_INSTALL=	cpuid scotch # bin/cpuid bin/gmap

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C|\.|-|g}
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	SIMD

SIMD_CONFIGURE_OFF=	--disable-builtin-popcount --disable-simd

.include <bsd.port.mk>
