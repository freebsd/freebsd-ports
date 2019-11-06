# $FreeBSD$

PORTNAME=	plinkseq
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	biology science
MASTER_SITES=	http://psychgen.u.hpc.mssm.edu/plinkseq_downloads/
# Default DISTNAME is correct, so leave it alone.
DISTFILES=	${PORTNAME}-src-${PORTVERSION}.tgz

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Toolset for working with human genetic variation data

BROKEN=		unfetchable

LICENSE=	GPLv2

BROKEN_aarch64=		Does not build: Host architecture was not detected as supported by protobuf
BROKEN_mips64=		Does not build: Host architecture was not detected as supported by protobuf
BROKEN_powerpc64=	Does not build: atomicops.h: error: stray '\#' in program

USES=		libtool gmake

post-patch:
	${REINPLACE_CMD} \
		-e 's|PF_INET|AF_INET|g' \
		${WRKSRC}/sources/mongoose/sources/lib/mongoose.c
	${REINPLACE_CMD} \
		-e 's|g++|${CXX}|g' \
		-e 's|gcc|${CC}|g' \
		-e 's|CXXFLAGS = -O3|CXXFLAGS = ${CXXFLAGS}|g' \
		-e 's|ALL_CFLAGS =-O3|ALL_CFLAGS = ${CFLAGS}|g' \
		${WRKSRC}/config_defs.Makefile
	${REINPLACE_CMD} \
		-e 's| -ldl||g' \
		-e 's| $$(STATIC_FLAG)||g' \
		${WRKSRC}/Makefile

do-install:
.for f in behead browser gcol mm mongoose pdas pseq smp tab2vcf
	${INSTALL_PROGRAM} ${WRKSRC}/build/execs/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/sources/plinkseq/build/lib/libplinkseq.a \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
