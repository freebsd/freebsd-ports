# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	dynamips
PORTVERSION=	0.2.10
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/Dynamips/${PORTVERSION}
PKGNAMESUFFIX=	-community
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Cisco 1700/2600/3600/3700/7200 Simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libelf.so:${PORTSDIR}/devel/libelf \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFLICTS=	dynamips-[0-9]* dynamips-devel-[0-9]*

USES=		gmake
USE_ZIP=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS UNSTABLE
UNSTABLE_DESC=	development code (x64 Mac)

LDFLAGS+=	-luuid
MAKE_ENV=	DYNAMIPS_CODE=${DYNAMIPS_CODE} \
		DYNAMIPS_ARCH=${DYNAMIPS_ARCH} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export \
		man/man1/${PORTNAME}.1.gz man/man1/nvram_export.1.gz \
		man/man7/hypervisor_mode.7.gz

PORTDOCS=	*

.if ${PORT_OPTIONS:MUNSTABLE}
DYNAMIPS_CODE=	"unstable"
.else
DYNAMIPS_CODE=	"stable"
.endif

DYNAMIPS_ARCH=	"nojit"

.if ${ARCH} == "i386"
DYNAMIPS_ARCH=	"x86"
.elif ${ARCH} == "amd64" || ${ARCH} == "x86_64"
DYNAMIPS_ARCH=	"amd64"
.elif ${ARCH} == "powerpc" && ${DYNAMIPS_CODE} == "unstable"
DYNAMIPS_ARCH=	"ppc32"
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
DYNAMIPS_ARCH=	"nojit"
.endif

#BROKEN_ia64=	does not compile: invokes i386 assembler
#BROKEN_sparc64=	${BROKEN_ia64}
#BROKEN_powerpc=	${BROKEN_ia64}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.${DYNAMIPS_CODE} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${DYNAMIPS_CODE}/nvram_export ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/nvram_export.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hypervisor_mode.7 ${STAGEDIR}${MANPREFIX}/man/man7

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.hypervisor ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
