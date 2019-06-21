# Created by: Bob Zimmermann <rpz@cse.wustl.edu>
# $FreeBSD$

PORTNAME=	gmap
PORTVERSION=	2015.09.21
CATEGORIES=	biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
DISTNAME=	${PORTNAME}-gsnap-${PORTVERSION:C|\.|-|g}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences

LICENSE=	GMAP
LICENSE_NAME=	GMAP License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN_aarch64=		invokes x86 assembler
BROKEN_armv6=		invokes x86 assembler
BROKEN_armv7=		invokes x86 assembler
BROKEN_mips64=		invokes x86 assembler
BROKEN_sparc64=		invokes x86 assembler

USES=		gmake perl5
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C|\.|-|g}

OPTIONS_DEFINE=	SIMD

SIMD_CONFIGURE_OFF=	--disable-builtin-popcount --disable-simd

.include <bsd.port.pre.mk>

# shebang_fix operates during patch.
# These scripts are created during configure.
post-configure:
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' \
		${WRKSRC}/Makefile ${WRKSRC}/util/*.pl
.if ${ARCH:Mpowerpc*}
# XXX MCL unknown why this shows up as true.  knowledge of autoconf needed.
	${REINPLACE_CMD} -e 's|#define HAVE_ASM_BSR 1||' \
		${WRKSRC}/src/config.h
.endif

.include <bsd.port.post.mk>
