# $FreeBSD$

PORTNAME=		canu
DISTVERSION=		2.1
CATEGORIES=		biology java perl5
# Github auto-generated tarballs lack submodules
MASTER_SITES=		https://github.com/marbl/canu/releases/download/v2.1/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Single molecule sequence assembler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/README.license.GPL

BROKEN_powerpc64=	fails to build: utgcns/libboost/boost/smart_ptr/detail/sp_counted_impl.hpp:81:5: error: 'get_deleter' declared as a 'virtual' field
NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	__int128 is not supported on this target

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:openmp gmake perl5
USE_JAVA=	yes

JAVA_RUN=	yes
JAVA_VERSION=	1.8+

WRKSRC_SUBDIR=	src
# Upstream Makefile compiles directly into ${DESTDIR}${PREFIX} rather than
# using a separate install target.
MAKE_ENV=	DESTDIR=${WRKSRC} CANU_BUILD_ENV=ports

.include <bsd.port.pre.mk>

# GCC 4.2.1 (still base compiler on some 2nd tier platforms) cannot build canu
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
USE_GCC=	yes
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
