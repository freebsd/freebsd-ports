# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	dynamips
PORTVERSION=	0.2.8
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/Dynamips/${PORTVERSION}-RC3${PKGNAMESUFFIX}
PKGNAMESUFFIX=	-community
DISTNAME=	${PORTNAME}-${PORTVERSION}-RC3${PKGNAMESUFFIX}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	Cisco 1700/2600/3600/3700/7200 Simulator

LIB_DEPENDS=	elf.0:${PORTSDIR}/devel/libelf \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

LICENSE=	GPLv2

CONFLICTS=	dynamips-[0-9]* dynamips-devel-[0-9]*

USE_GMAKE=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	UNSTABLE
UNSTABLE_DESC=	development code (x64 Mac)

LDFLAGS+=	-luuid
MAKE_ENV=	\
		DYNAMIPS_CODE=${DYNAMIPS_CODE} \
		DYNAMIPS_ARCH=${DYNAMIPS_ARCH} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export
PORTDOCS=	*
.if !defined(NO_INSTALL_MANPAGES)
MAN1=		${PORTNAME}.1 nvram_export.1
MAN7=		hypervisor_mode.7
.endif

.if ${PORT_OPTIONS:MUNSTABLE}
DYNAMIPS_CODE=	"unstable"
.else
DYNAMIPS_CODE=	"stable"
.endif

.if ${ARCH} == "i386"
DYNAMIPS_ARCH=	"x86"
.elif ${ARCH} == "amd64"
DYNAMIPS_ARCH=	"amd64"
.elif ${ARCH} == "sparc64"
BROKEN=		Does not compile
.elif ${ARCH} == "powerpc"
DYNAMIPS_ARCH=	"ppc32"
BROKEN=		Does not compile: uses i386 asm
.else
DYNAMIPS_ARCH=	"nojit"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.${DYNAMIPS_CODE} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${DYNAMIPS_CODE}/nvram_export ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.community ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.hypervisor ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nvram_export.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/hypervisor_mode.7 ${PREFIX}/man/man7
.endif

.include <bsd.port.post.mk>
