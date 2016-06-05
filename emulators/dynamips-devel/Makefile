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

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
LIB_DEPENDS=	libelf.so.0:devel/libelf

CONFLICTS=	dynamips-[0-9]* dynamips-community-[0-9]*

USES=		gmake
ALL_TARGET=	${PORTNAME} nvram_export
MAKE_ENV=	DYNAMIPS_ARCH=${DYNAMIPS_ARCH} \
		HAS_POSIX_MEMALIGN=1
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
