# New ports collection makefile for: mingw-gcc
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mingw
PKGNAMEPREFIX=	mingw-
DISTNAME=	${PORTNAME}-${PORTVERSION}-20010828-src
DIST_SUBDIR=	mingw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FSF gcc-2.95.3 for Windows cross-development

BUILD_DEPENDS=	${LOCALBASE}/i386-mingw32msvc/bin/as:${PORTSDIR}/devel/mingw-binutils \
		${LOCALBASE}/bin/mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt
RUN_DEPENDS=	${LOCALBASE}/i386-mingw32msvc/bin/as:${PORTSDIR}/devel/mingw-binutils \
		${LOCALBASE}/bin/mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt

WRKSRC=		${WRKDIR}/gcc-${PORTVERSION}-20010828

USE_AUTOTOOLS=	autoconf:253:env
USE_GMAKE=	yes
WITHOUT_CPU_CFLAGS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=i386-mingw32msvc \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/i386-mingw32msvc/${PORTVERSION}/include/g++

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAN1=	cccp.1                 \
	i386-mingw32msvc-g++.1 \
	i386-mingw32msvc-g77.1 \
	i386-mingw32msvc-gcc.1
INFO=	cpp g77 gcc

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	${REINPLACE_CMD} -e 's/install-libiberty//' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -E -e 's/([^x])str(error|signal).[co]/\1/g' \
		${WRKSRC}/libiberty/Makefile.in ${WRKSRC}/libstdc++/Makefile.in

pre-install:
	${MV} ${PREFIX}/bin/i386-mingw32msvc-c++filt \
		${PREFIX}/bin/i386-mingw32msvc-c++filt.binutils

post-install:
	@for file in \
	  cpp gcov  \
	  i386-mingw32msvc-c++ \
	  i386-mingw32msvc-c++filt \
	  i386-mingw32msvc-g++ \
	  i386-mingw32msvc-g77 \
	  i386-mingw32msvc-gcc \
	  i386-mingw32msvc-protoize \
	  i386-mingw32msvc-unprotoize; \
	do \
	  ${STRIP_CMD} ${PREFIX}/bin/$${file}; \
	done

.include <bsd.port.post.mk>
