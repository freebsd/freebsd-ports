PORTNAME=	7-zip
DISTVERSION=	26.00
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	https://www.7-zip.org/a/
DISTNAME=	7z${DISTVERSION:S/.//}-src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Console version of the 7-Zip file archiver
WWW=		https://www.7-zip.org/

LICENSE=	BSD3CLAUSE LGPL21+ UNRAR
LICENSE_COMB=	multi
LICENSE_NAME_UNRAR=	unRAR license
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/DOC/License.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/DOC/copying.txt
LICENSE_FILE_UNRAR=	${WRKSRC}/DOC/unRarLicense.txt
LICENSE_PERMS_UNRAR=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		7z cpe dos2unix gmake

CPE_VENDOR=	7-zip

MAKEFILE=	../../cmpl_clang.mak
MAKE_ARGS=	LOCAL_FLAGS="${CFLAGS}"
CFLAGS_aarch64?=	-march=armv8-a+crc+crypto

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Bundles/Alone2
DOS2UNIX_FILES=	C/CpuArch.h \
		CPP/7zip/7zip_gcc.mak \
		CPP/7zip/var_gcc.mak

PLIST_FILES=	bin/7z \
		bin/7zz \
		share/man/man1/7zz.1.gz
PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt \
		lzma.txt readme.txt src-history.txt

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFAULT_amd64=	ASM

ASM_BUILD_DEPENDS=	jwasm:devel/jwasm
ASM_MAKE_ARGS=		IS_X64=1 USE_ASM=1 USE_JWASM=1

post-patch:
	${ECHO_CMD} > ${WRKSRC}/CPP/7zip/warn_clang.mak

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/b/c/7zz ${STAGEDIR}/${PREFIX}/bin
	${LN} -sf 7zz ${STAGEDIR}/${PREFIX}/bin/7z
	${INSTALL_MAN} ${FILESDIR}/7zz.1 ${STAGEDIR}/${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${PORTDOCS:C,^,${WRKSRC}/DOC/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
