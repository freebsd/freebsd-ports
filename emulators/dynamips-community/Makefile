# Created by: Pavel I Volkov <pavelivolkov@googlemail.com>
# $FreeBSD$

PORTNAME=	dynamips
PORTVERSION=	0.2.17
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators
PKGNAMESUFFIX=	-community

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Cisco 1700/2600/3600/3700/7200 Simulator

LICENSE=	GPLv2

LIB_DEPENDS=	libelf.so:devel/libelf

BROKEN_powerpc=		fails to compile: invokes x86 assembler
BROKEN_sparc64=		fails to compile: invokes x86 assembler

CFLAGS+=	-I${PREFIX}/include/libelf

CONFLICTS=	dynamips-[0-9]* dynamips-devel-[0-9]*

USES=		cmake:insource
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

GH_ACCOUNT=	GNS3

CMAKE_ARGS+=	-DDYNAMIPS_CODE=${DYNAMIPS_CODE} -DDYNAMIPS_ARCH=${DYNAMIPS_ARCH}

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export \
		man/man1/${PORTNAME}.1.gz man/man1/nvram_export.1.gz \
		man/man7/hypervisor_mode.7.gz

PORTDOCS=	*

DYNAMIPS_CODE=	stable

.if ${OPSYS} == FreeBSD
DYNAMIPS_ARCH=	nojit
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DYNAMIPS_CODE}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${DYNAMIPS_CODE}/nvram_export ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/nvram_export.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hypervisor_mode.7 ${STAGEDIR}${MANPREFIX}/man/man7

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README.md README.hypervisor RELEASE-NOTES ChangeLog MAINTAINERS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
