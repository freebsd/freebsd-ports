# New ports collection makefile for: mingw-gcc
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR= gcc/releases/${DISTNAME}
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-chill-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g77-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-java-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-objc-${PORTVERSION}${EXTRACT_SUFX}

PKGNAMEPREFIX=	mingw-

PATCH_SITES=	http://www.ab.wakwak.com/~tino/windows/
PATCHFILES=	${PKGNAME}-1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tino@pa2.so-net.ne.jp

BUILD_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt \
		autoheader:${PORTSDIR}/devel/autoconf
RUN_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=i386-mingw32msvc \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/i386-mingw32msvc/${PORTVERSION}/include/g++

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAN1=	cccp.1                 \
	i386-mingw32msvc-g++.1 \
	i386-mingw32msvc-g77.1 \
	i386-mingw32msvc-gcc.1

post-install:
	@for file in \
	  cpp gcjh gcov jcf-dump jv-scan \
	  i386-mingw32msvc-c++ \
	  i386-mingw32msvc-c++filt \
	  i386-mingw32msvc-g++ \
	  i386-mingw32msvc-g77 \
	  i386-mingw32msvc-gcc \
	  i386-mingw32msvc-gcj \
	  i386-mingw32msvc-protoize \
	  i386-mingw32msvc-unprotoize; \
	do \
	  strip ${PREFIX}/bin/$${file}; \
	done
	@rm ${PREFIX}/info/chill.info

.include <bsd.port.mk>
