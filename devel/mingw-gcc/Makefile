# New ports collection makefile for: mingw-gcc
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= mingw
PKGNAMEPREFIX=	mingw-
DISTNAME=	gcc-${PORTVERSION}-20010723-src
DIST_SUBDIR=	mingw

MAINTAINER=	doc@hisio.safenet.pl

BUILD_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt \
		autoheader:${PORTSDIR}/devel/autoconf
RUN_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt

NO_WRKSUBDIR=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=i386-mingw32msvc \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/i386-mingw32msvc/${PORTVERSION}/include/g++

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAN1=	cccp.1                 \
	i386-mingw32msvc-g++.1 \
	i386-mingw32msvc-g77.1 \
	i386-mingw32msvc-gcc.1

post-patch:
	${PERL} -i.orig -pe 's/install-libiberty//' ${WRKSRC}/Makefile.in

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
	  strip ${PREFIX}/bin/$${file}; \
	done

.include <bsd.port.mk>
