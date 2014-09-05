# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	dynamips
DISTVERSION=	0.2.8-RC2
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.ipflow.utc.fr/dynamips/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cisco 1700/2600/3600/3700/7200 Simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libelf.so.0:${PORTSDIR}/devel/libelf

CONFLICTS=	dynamips-[0-9]* dynamips-community-[0-9]*

USES=		gmake
ALL_TARGET=	${PORTNAME} nvram_export
MAKE_ENV=	DYNAMIPS_ARCH=${DYNAMIPS_ARCH}\
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}\
		PTHREAD_LIBS=${PTHREAD_LIBS}
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export
PLIST_FILES+=	man/man1/${PORTNAME}.1.gz man/man1/nvram_export.1.gz
PLIST_FILES+=	man/man7/hypervisor_mode.7.gz
PORTDOCS=	README README.hypervisor

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
.if ${OSVERSION} < 700021
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nvram_export ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.hypervisor ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nvram_export.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/hypervisor_mode.7 ${STAGEDIR}${PREFIX}/man/man7

.include <bsd.port.post.mk>
