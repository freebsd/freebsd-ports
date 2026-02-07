PORTNAME=	sdcc
DISTVERSIONPREFIX=	src-
DISTVERSION=	4.4.0
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	darius@dons.net.au
COMMENT=	Small Device C Compiler
WWW=		https://sdcc.sourceforge.net/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3=	${WRKSRC}/sdas/COPYING3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/adjacency_list.hpp:devel/boost-libs \
		gpasm:devel/gputils
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		autoreconf:build bison compiler:c++11-lang gmake iconv \
		localbase python readline shebangfix tar:bzip2
SHEBANG_FILES=	support/scripts/as2gbmap.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-non-free \
		docdir=${DOCSDIR}

MAKE_JOBS_UNSAFE=	yes

TEST_ARGS=	--no-print-directory # tons of them, way too annoying
TEST_TARGET=	all

CONFLICTS_INSTALL=	sdcc sdcc-devel

TEST_WRKSRC=	${WRKSRC}/support/regression
WRKSRC=		${WRKDIR}/sdcc-${DISTVERSION}

PLIST_SUB=	CONFIGURE_TARGET=${CONFIGURE_TARGET}
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

post-patch:
	@${REINPLACE_CMD} '/install:/s/:.*/:/' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sdas/linksrc/Makefile.in \
		${WRKSRC}/support/sdbinutils/libiberty/Makefile.in
	@${REINPLACE_CMD} '/^SUBDIRS =/s/doc//' \
		${WRKSRC}/support/sdbinutils/bfd/Makefile.in
	@${REINPLACE_CMD} 's/[[:<:]]ARCH[[:>:]]/PICARCH/g' \
		${WRKSRC}/device/lib/pic14/Makefile.common \
		${WRKSRC}/device/lib/pic14/Makefile.in \
		${WRKSRC}/device/lib/pic14/configure \
		${WRKSRC}/device/lib/pic14/configure.ac \
		${WRKSRC}/device/lib/pic14/libc/Makefile.in \
		${WRKSRC}/device/lib/pic14/libm/Makefile.in \
		${WRKSRC}/device/lib/pic14/libsdcc/enhanced/Makefile.in \
		${WRKSRC}/device/lib/pic14/libsdcc/enhanced-no-xinst/Makefile.in \
		${WRKSRC}/device/lib/pic14/libsdcc/regular/Makefile.in \
		${WRKSRC}/device/lib/pic16/Makefile.in \
		${WRKSRC}/device/lib/pic16/configure \
		${WRKSRC}/device/lib/pic16/configure.ac \
		${WRKSRC}/device/lib/pic16/debug/Makefile.in \
		${WRKSRC}/device/lib/pic16/libc/Makefile.in \
		${WRKSRC}/device/lib/pic16/libio/Makefile.in \
		${WRKSRC}/device/lib/pic16/libm/Makefile.in \
		${WRKSRC}/device/lib/pic16/libsdcc/Makefile.in \
		${WRKSRC}/device/lib/pic16/startup/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic14/Makefile.common.in \
		${WRKSRC}/device/non-free/lib/pic14/Makefile.rules \
		${WRKSRC}/device/non-free/lib/pic16/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic16/configure \
		${WRKSRC}/device/non-free/lib/pic16/configure.ac \
		${WRKSRC}/device/non-free/lib/pic16/libdev/Makefile.in \
		${WRKSRC}/device/non-free/lib/pic16/libdev/mkmk.sh
	@${REINPLACE_CMD} 's/[[:<:]]arch[[:>:]]/picarch/g' \
		${WRKSRC}/device/non-free/lib/pic16/libdev/mkmk.sh

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's, [a-z-]*doc,,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/sim/ucsim/packages_in.mk

post-install:
	${FIND} -d ${STAGEDIR}${DATADIR} -type d -empty -delete

.include <bsd.port.mk>
