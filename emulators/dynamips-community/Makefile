# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	dynamips
PORTVERSION=	0.2.15
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators
PKGNAMESUFFIX=	-community

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Cisco 1700/2600/3600/3700/7200 Simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libelf.so:${PORTSDIR}/devel/libelf \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

CFLAGS+=	-I${PREFIX}/include/libelf

CONFLICTS=	dynamips-[0-9]* dynamips-devel-[0-9]*

USES=		cmake
USE_GITHUB=	yes

MAKE_JOBS_UNSAFE=	yes

GH_ACCOUNT=	GNS3
GH_PROJECT=	dynamips

MAKE_ENV=	DYNAMIPS_CODE=${DYNAMIPS_CODE} \
		DYNAMIPS_ARCH=${DYNAMIPS_ARCH}

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export \
		man/man1/${PORTNAME}.1.gz man/man1/nvram_export.1.gz \
		man/man7/hypervisor_mode.7.gz

PORTDOCS=	*

DYNAMIPS_CODE=	stable

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
DYNAMIPS_ARCH=	nojit
.endif

BROKEN_ia64=	does not compile: invokes i386 assembler
BROKEN_sparc64=	${BROKEN_ia64}
BROKEN_powerpc=	${BROKEN_ia64}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DYNAMIPS_CODE}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${DYNAMIPS_CODE}/nvram_export ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/nvram_export.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hypervisor_mode.7 ${STAGEDIR}${MANPREFIX}/man/man7

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README README.hypervisor RELEASE-NOTES ChangeLog MAINTAINERS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
