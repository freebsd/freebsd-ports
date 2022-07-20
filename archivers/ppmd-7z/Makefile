PORTNAME=	ppmd
PORTVERSION=	9.04
CATEGORIES=	archivers
MASTER_SITES=	SF/p7zip/p7zip/${PORTVERSION}
PKGNAMESUFFIX=	-7z
DISTNAME=	p7zip_${DISTVERSION}_src_all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-ratio PPMD compressor

LICENSE=	LGPL21+ UNRAR
LICENSE_COMB=	multi
LICENSE_NAME_UNRAR=	unRAR license
LICENSE_FILE=	${WRKSRC}/DOCS/License.txt
LICENSE_FILE_UNRAR=	${WRKSRC}/DOCS/unRarLicense.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/DOCS/copying.txt
LICENSE_PERMS_UNRAR=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe tar:bzip2 gmake
WRKSRC=		${WRKDIR}/p7zip_${DISTVERSION}
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Compress/PPMD_Alone
MAKEFILE=	makefile
PLIST_FILES=	bin/${PKGBASE}
MAKE_ARGS=	PROG=${PORTNAME} CXX="${CXX}" LIB="-pthread"
TEST_TARGET=	test
CPE_VENDOR=	7-zip
CPE_PRODUCT=	p7zip

post-patch:
	@${REINPLACE_CMD} -e '/bool Open(LPCTSTR fileName, DWORD creationDisposition)/,/}/d'\
		${WRKSRC}/CPP/7zip/Common/FileStreams.h
	@${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|;s|-o |${CFLAGS} -o |'\
			${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGBASE}

.include <bsd.port.mk>
