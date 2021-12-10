PORTNAME=	7-zip
DISTVERSION=	21.06
CATEGORIES=	archivers
MASTER_SITES=	https://www.7-zip.org/a/
DISTNAME=	7z${DISTVERSION:S/.//}-src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Console version of the 7-Zip file archiver

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		7z dos2unix gmake localbase

MAKEFILE=	../../cmpl_clang.mak
MAKE_ARGS=	LOCAL_FLAGS="${CFLAGS}" \
		LOCAL_LIBS="${LIBS} -lsysinfo"

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Bundles/Alone2
DOS2UNIX_FILES=	CPP/7zip/7zip_gcc.mak \
		CPP/7zip/var_gcc.mak \
		CPP/Windows/SystemInfo.cpp

PLIST_FILES=	bin/7zz
PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt lzma.txt readme.txt \
		src-history.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	${ECHO_CMD} > ${WRKSRC}/CPP/7zip/warn_clang.mak

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/b/c/7zz ${STAGEDIR}/${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${PORTDOCS:C,^,${WRKSRC}/DOC/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
