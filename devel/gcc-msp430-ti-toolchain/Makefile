# $FreeBSD$

PORTNAME=	gcc-msp430-ti-toolchain
PORTVERSION=	${GCC_VERSION}.${TI_VERSION}.${RELEASE_DATE}
CATEGORIES=	devel
MASTER_SITES=	http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/${TI_VERSION:S/./_/g}/exports/ \
		http://www.ti.com/lit/ml/slau591a/:docs
DISTFILES=	msp430-gcc-source.tar.bz2 \
		msp430-gcc-support-files.zip \
		slau591a.pdf:docs
DIST_SUBDIR=	mspgcc${TI_VERSION}
EXTRACT_ONLY=	msp430-gcc-source.tar.bz2 \
		msp430-gcc-support-files.zip

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete gcc-based toolcahin for TI MSP430 uC

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	expect:${PORTSDIR}/lang/expect

USES=		bison compiler cpe gmake iconv libtool makeinfo tar:bzip2
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--target=${TARGET} \
		--enable-languages=c,c++ \
		--disable-nls

GNU_CONFIGURE_PREFIX=	${PREFIX}/${SUBPREFIX}

USE_CSTD=	gnu89

MAKE_JOBS_UNSAFE=	yes

GCC_VERSION=	4.9.1
TI_VERSION=	3.05.00.00
RELEASE_DATE=	20150915
TARGET=		msp430-elf

CPE_PRODUCT=	gcc
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

WRKSRC=		${WRKDIR}/sources/tools
CONFIGURE_WRKSRC=${WRKDIR}/build
CONFIGURE_SCRIPT=../sources/tools/configure
BUILD_WRKSRC=	${WRKDIR}/build
INSTALL_WRKSRC=	${WRKDIR}/build

SUBPREFIX=	${PORTNAME}-${TI_VERSION}

MANPREFIX=	${GNU_CONFIGURE_PREFIX}
DOCSDIR=	${GNU_CONFIGURE_PREFIX}/docs
PLIST_SUB+=	TARGET=${TARGET} GCC_VERSION=${GCC_VERSION} \
		TI_VERSION=${TI_VERSION}

UNNEEDED_HOST_FILES=	lib/lib${TARGET}-sim.a lib/libtcl8.4.a \
			lib/libtclstub8.4.a lib/libtk8.4.a \
			lib/libtkstub8.4.a lib/tclConfig.sh \
			lib/tkConfig.sh lib/itclConfig.sh \
			lib/itcl3.3/libitclstub3.3.a

UNNEEDED_HOST_DIRS=	include info man share

pre-extract:
	@${MKDIR} ${BUILD_WRKSRC}

post-stage:
	@${ECHO_MSG} "Remove unneeded host files..."
	@for f in ${UNNEEDED_HOST_FILES} ; do \
		${RM} "${STAGEDIR}${GNU_CONFIGURE_PREFIX}/$$f" ; \
	done
	@for f in ${UNNEEDED_HOST_DIRS} ; do \
		${RM} -rf "${STAGEDIR}${GNU_CONFIGURE_PREFIX}/$$f" ; \
	done
	@${ECHO_MSG} "Install devices' headers and linker scripts..."
	@${MKDIR} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/include
	cd ${WRKDIR}/msp430-gcc-support-files && \
		${TAR} cf - . | ${TAR} xf - -C ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/include
	@${ECHO_MSG} "Install minimal documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/slau591a.pdf \
		${STAGEDIR}${DOCSDIR}/slau591a.pdf
	${INSTALL_MAN} ${FILESDIR}/watchdog.txt \
		${STAGEDIR}${DOCSDIR}/watchdog.txt

.include <bsd.port.mk>
