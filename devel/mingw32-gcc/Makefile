# New ports collection makefile for: mingw-gcc
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= gcc
PKGNAMEPREFIX=	mingw-

PATCH_SITES=	http://www.ab.wakwak.com/~tino/windows/
PATCHFILES=	${PKGNAME}-1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tino@pa2.so-net.ne.jp

BUILD_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=i386-mingw32msvc \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/i386-mingw32msvc/${PORTVERSION}/include/g++

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAN1=	cccp.1                 \
	i386-mingw32msvc-g++.1 \
	i386-mingw32msvc-g77.1 \
	i386-mingw32msvc-gcc.1

post-configure:
	cd ${WRKSRC}/gcc; ${GMAKE} installdirs

post-install:
	@for file in \
	  c++ cpp g++ g77 gcc gcj gcjh gcov \
	  jcf-dump jv-scan protoize unprotoize; \
	do \
	  file1=${PREFIX}/bin/$${file}; \
	  file2=${PREFIX}/bin/i386-mingw32msvc-$${file}; \
	  if [ -f $${file1} ] && [ ! -f $${file2} ]; \
	  then \
	    ${CP} $${file1} $${file2}; \
	  fi; \
	  strip $${file2}; \
	done
.for f in chill.info cpp.info g77.info gcc.info
	@install-info ${PREFIX}/info/${f} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
