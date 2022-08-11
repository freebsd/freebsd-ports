PORTNAME=	bitkeeper
PORTVERSION=	7.3.3
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://www.bitkeeper.org/downloads/${PORTVERSION}/
DISTNAME=	bk-${PORTVERSION}.src

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Scalable Distributed Source Management System

LICENSE=	APACHE20

BROKEN_aarch64=		ld: error: undefined symbol: fpsetround
BROKEN_riscv64=		fails to compile: src/gui/tcltk/tcl/unix/tclUnixInit.c:401:16: error: use of undeclared identifier 'FP_RN'

BUILD_DEPENDS=	${LOCALBASE}/bin/gperf:devel/gperf \
		${LOCALBASE}/include/tommath.h:math/libtommath \
		bash:shells/bash
LIB_DEPENDS=	libtomcrypt.so:security/libtomcrypt \
		libpcre.so:devel/pcre	\
		liblz4.so:archivers/liblz4 \
		libtommath.so:math/libtommath \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	bash:shells/bash

USES=		gmake groff bison localbase tk xorg iconv pkgconfig
USE_XORG=	x11 xrender xft

SUB_FILES=	bk bk-man.conf
MANDIRS=	${PREFIX}/bitkeeper/man

WRKSRC=		${WRKDIR}/bk-${PORTVERSION}/src
ALL_TARGET=	p

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's/DESTDIR/PDESTDIR/g'

do-build:
	@(cd ${WRKSRC}; ${MAKE_CMD} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; \
	${MAKE_CMD} PDESTDIR=${STAGEDIR}${PREFIX} ${INSTALL_TARGET})
	${INSTALL_SCRIPT} ${WRKDIR}/bk ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/bk-man.conf \
		${STAGEDIR}${PREFIX}/etc/man.d/bk.conf

.include <bsd.port.mk>
