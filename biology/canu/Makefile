PORTNAME=		canu
DISTVERSION=		2.2
PORTREVISION=		8
CATEGORIES=		biology java perl5
# Github auto-generated tarballs lack submodules
MASTER_SITES=		https://github.com/marbl/canu/releases/download/v${DISTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Single molecule sequence assembler
WWW=		https://canu.readthedocs.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/README.license.GPL

NOT_FOR_ARCHS=		armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	Requires 64-bit processor

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:c++11-lang gmake java localbase perl5 tar:xz
USE_CXXSTD=	c++14

# Upstream Makefile compiles directly into ${DESTDIR}${PREFIX} rather than
# using a separate install target.
MAKE_ENV=	DESTDIR=${WRKSRC} CANU_BUILD_ENV=ports

WRKSRC_SUBDIR=	src

.include <bsd.port.pre.mk>

# Parasail should be unbundled, but that would be a project because it's
# currently woven into the canu code
post-extract:
.if ${ARCH} == "aarch64"
	${CP} ${FILESDIR}/cpuid_arm.c ${WRKSRC}/utility/src/parasail/cpuid.c
.elif ${ARCH} == "powerpc64" || ${ARCH} == "powerpc64le"
	${CP} ${FILESDIR}/cpuid_ppc.c ${WRKSRC}/utility/src/parasail/cpuid.c
.elif ${ARCH} != "amd64"
	${CP} ${FILESDIR}/cpuid_any.c ${WRKSRC}/utility/src/parasail/cpuid.c
.endif

pre-configure:
	@${REINPLACE_CMD} \
		-e 's|-O4||g' \
		-e 's|-funroll-loops||g' \
		-e 's|-fexpensive-optimizations||g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|RealBin/../lib/site_perl|RealBin/../${SITE_PERL_REL}/canu|g' \
		${WRKSRC}/pipelines/canu.pl

# Upstream does not want to use lib/perl5/site_perl
post-build:
	@${MKDIR} ${WRKSRC}/build/lib/perl5
	${MV} ${WRKSRC}/build/lib/site_perl ${WRKSRC}/build/lib/perl5

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	(cd ${WRKSRC}/build && ${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX})
	# STRIP_CMD fails without this under poudriere
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} \
		`file ${STAGEDIR}${PREFIX}/bin/* | ${GREP} ELF | cut -d : -f 1`
	(cd ${WRKSRC}/build && \
		${COPYTREE_SHARE} "lib share" ${STAGEDIR}${PREFIX})

.include <bsd.port.post.mk>
