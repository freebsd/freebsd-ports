# $FreeBSD$

PORTNAME=	optimfrog
PORTVERSION=	5.100
CATEGORIES=	audio
MASTER_SITES=	http://losslessaudio.org/Downloads/A1C0/${DISTVERSION:S/.//}/FreeBSD/
DISTNAME=	# OptimFROG_FreeBSD_${ARCH}_${DISTVERSION:S/.//}

MAINTAINER=	matthew@reztek.cz
COMMENT?=	Best-ratio lossless audio codec

LICENSE=	OptimFROG
LICENSE_NAME=	OptimFROG - License
LICENSE_FILE=	${WRKSRC}/license.html	#only available as html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CONFLICTS_INSTALL?=	optimfrog-sse2-[0-9]*

ONLY_FOR_ARCHS?=	amd64 i386

USES=		tar:txz

NO_CDROM=	No fees may be collected for redistribution
NO_BUILD=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE_i386=	SSE2
OPTIONS_DEFINE?=	#
SSE2_DESCR=	Use SSE2 instructions instead of x87 FP

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
DISTNAME=	OptimFROG_FreeBSD_x64_${DISTVERSION:S/.//}
.else # ${ARCH} == "i386"
. if ${PORT_OPTIONS:MSSE2}
DISTNAME=	OptimFROG_FreeBSD_x86_SSE2_${DISTVERSION:S/.//}
. else
DISTNAME=	OptimFROG_FreeBSD_x86_${DISTVERSION:S/.//}
. endif
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libstdc++.so.6:misc/compat9x
.endif

do-install:
	@(cd ${WRKSRC} && ./install.sh -d ${STAGEDIR})

.include <bsd.port.post.mk>
