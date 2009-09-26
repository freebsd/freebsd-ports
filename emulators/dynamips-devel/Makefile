# New ports collection makefile for:	dynamips
# Date created:				21 Mar 2007
# Whom:					Pavel Volkov <pol@opk.ru>
#
# $FreeBSD$
#

PORTNAME=	dynamips
DISTVERSION=	0.2.8-RC2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.ipflow.utc.fr/dynamips/
PKGNAMESUFFIX=	-devel

MAINTAINER=	pol@iib.ru
COMMENT=	Cisco 1700/2600/3600/3700/7200 Simulator

LIB_DEPENDS=	elf.0:${PORTSDIR}/devel/libelf

CONFLICTS=	dynamips-[0-9]*

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME} nvram_export
MAKE_ENV=	DYNAMIPS_ARCH=${DYNAMIPS_ARCH}\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}\
		PTHREAD_LIBS=${PTHREAD_LIBS}\
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export
.if !defined(NOPORTDOCS)
PORTDOCS=	README README.hypervisor
.endif
.if !defined(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1 nvram_export.1
MAN7=		hypervisor_mode.7
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.if ${ARCH} == "i386"
DYNAMIPS_ARCH=	"x86"
.elif ${ARCH} == "amd64"
DYNAMIPS_ARCH=	"amd64"
.else
DYNAMIPS_ARCH=	"nojit"
.endif

# It required libpcap version 0.9.4 or is higher.
.if ${OSVERSION} < 602100 || (${OSVERSION} >= 700000 && ${OSVERSION} < 700021)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
MAKE_ENV+=	PCAP_LIB=${LOCALBASE}/lib/libpcap.a
#.warning Do not overlook, make libpcap with LIBPCAP_OVERWRITE_BASE parameter, for use with shared library.
#LIB_DEPENDS+=	pcap.\(0.9.\)?[2-9]:${PORTSDIR}/net/libpcap
#MAKE_ENV+=	PCAP_LIB=-lpcap.2
.endif

.if ${OSVERSION} >= 700013
MAKE_ENV+=	HAS_POSIX_MEMALIGN=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nvram_export ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.hypervisor ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nvram_export.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/hypervisor_mode.7 ${PREFIX}/man/man7
.endif

.include <bsd.port.post.mk>
