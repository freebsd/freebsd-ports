# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dynamips
DISTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.ipflow.utc.fr/dynamips/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cisco 3600/7200 Simulator

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LIB_DEPENDS=	libelf.so:devel/libelf

USES=		gmake
ALL_TARGET=	${PORTNAME} nvram_export
MAKE_ENV=	DYNAMIPS_ARCH=${DYNAMIPS_ARCH}
MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	dynamips-community-[0-9]* dynamips-devel-[0-9]*

PLIST_FILES=	bin/${PORTNAME} bin/nvram_export man/man1/${PORTNAME}.1.gz \
		man/man1/nvram_export.1.gz man/man7/hypervisor_mode.7.gz
PORTDOCS=	README README.hypervisor

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
DYNAMIPS_ARCH=	"x86"
.elif ${ARCH} == "amd64"
DYNAMIPS_ARCH=	"amd64"
.else
DYNAMIPS_ARCH=	"nojit"
.endif

MAKE_ENV+=	HAS_POSIX_MEMALIGN=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nvram_export ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.hypervisor ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nvram_export.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/hypervisor_mode.7 ${STAGEDIR}${PREFIX}/man/man7

.include <bsd.port.post.mk>
