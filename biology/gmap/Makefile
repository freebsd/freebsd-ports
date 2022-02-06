# Created by: Bob Zimmermann <rpz@cse.wustl.edu>

PORTNAME=	gmap
PORTVERSION=	2020.09.12
CATEGORIES=	biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
DISTNAME=	${PORTNAME}-gsnap-${PORTVERSION:C|\.|-|g}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences

LICENSE=	GMAP
LICENSE_NAME=	GMAP License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=		amd64 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	upstream supports only x86 and possibly POWER8

USES=		gmake perl5
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	cpuid scotch # bin/cpuid bin/gmap

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C|\.|-|g}
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	SIMD

SIMD_CONFIGURE_OFF=	--disable-builtin-popcount --disable-simd

.include <bsd.port.mk>
