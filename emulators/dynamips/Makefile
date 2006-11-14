# New ports collection makefile for:	dynamips
# Date created:				31 Jan 2006
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dynamips
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.ipflow.utc.fr/dynamips/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Cisco 3600/7200 Simulator

LIB_DEPENDS=	elf.0:${PORTSDIR}/devel/libelf

USE_GMAKE=	yes
USE_GCC=	3.2+
ALL_TARGET=	${PORTNAME}
MAKE_ENV=	DYNAMIPS_ARCH=${DYNAMIPS_ARCH}\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}\
		PTHREAD_LIBS=${PTHREAD_LIBS}

PLIST_FILES=	bin/${PORTNAME}
.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
DYNAMIPS_ARCH=	"x86"
.elif ${ARCH} == "amd64"
DYNAMIPS_ARCH=	"nojit"	# JIT does not work on amd64 for some reason
.else
DYNAMIPS_ARCH=	"nojit"
.endif

.if ${OSVERSION} < 602100 || ${OSVERSION} < 700021
#
# Requires libpcap 0.9.4
BUILD_DEPENDS+=	libpcap>=0.9.4:${PORTSDIR}/net/libpcap
.endif

.if ${OSVERSION} >= 700013
MAKE_ENV+=	HAS_POSIX_MEMALIGN=1
.endif

.include <bsd.port.post.mk>
