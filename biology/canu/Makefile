# $FreeBSD$

PORTNAME=		canu
DISTVERSIONPREFIX=	v
DISTVERSION=		1.9
PORTREVISION=		1
CATEGORIES=		biology java perl5

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Single molecule sequence assembler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/README.license.GPL

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:openmp gmake perl5
USE_JAVA=	yes
USE_GITHUB=	yes

JAVA_RUN=	yes
JAVA_VERSION=	1.8+
GH_ACCOUNT=	marbl

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
		-e 's|\\$$bin/mhap-|${JAVAJARDIR}/mhap-|g' \
		${WRKSRC}/pipelines/canu/OverlapMhap.pm
	@${REINPLACE_CMD} \
		-e 's|RealBin/lib|RealBin/../${SITE_PERL_REL}/canu|g' \
		${WRKSRC}/pipelines/canu.pl

# Upstream does not want to use lib/perl5/site_perl
post-build:
	@${MKDIR} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/perl5
	${MV} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/site_perl \
		${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/perl5

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	(cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX})
	# STRIP_CMD fails without this on 11.1 under poudriere
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} \
		`file ${STAGEDIR}${PREFIX}/bin/* | ${GREP} ELF | cut -d : -f 1`
	(cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && \
		${COPYTREE_SHARE} "lib share" ${STAGEDIR}${PREFIX})

.include <bsd.port.post.mk>
