PORTNAME=	7-zip
DISTVERSION=	21.07
CATEGORIES=	archivers
MASTER_SITES=	https://www.7-zip.org/a/
DISTNAME=	7z${DISTVERSION:S/.//}-src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Console version of the 7-Zip file archiver

LICENSE=	BSD3CLAUSE LGPL21+ UNRAR
LICENSE_COMB=	multi
LICENSE_NAME_UNRAR=	unRAR license
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/DOC/License.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/DOC/copying.txt
LICENSE_FILE_UNRAR=	${WRKSRC}/DOC/unRarLicense.txt
LICENSE_PERMS_UNRAR=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		7z cpe dos2unix gmake localbase

CPE_VENDOR=	7-zip

MAKEFILE=	../../cmpl_clang.mak
MAKE_ARGS=	LOCAL_FLAGS="${CFLAGS}" \
		LOCAL_LIBS="${LIBS} -lsysinfo"
CFLAGS_aarch64?=	-march=armv8-a+crc+crypto

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Bundles/Alone2
DOS2UNIX_FILES=	C/CpuArch.c \
		CPP/7zip/7zip_gcc.mak \
		CPP/7zip/var_gcc.mak \
		CPP/Windows/SystemInfo.cpp

PLIST_FILES=	bin/7zz
PORTDOCS=	7zC.txt 7zFormat.txt License.txt Methods.txt \
		lzma.txt readme.txt src-history.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	${ECHO_CMD} > ${WRKSRC}/CPP/7zip/warn_clang.mak

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/b/c/7zz ${STAGEDIR}/${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${PORTDOCS:C,^,${WRKSRC}/DOC/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
