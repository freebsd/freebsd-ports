# New ports collection makefile for:	mingw32-gcc
# Date created:		24 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}.${PATCHVERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	mingw32-
DISTFILES=	${PORTNAME}-core-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-g++-${GCCVERSION}${EXTRACT_SUFX}  \
		${PORTNAME}-objc-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-g77-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-ada-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-java-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-testsuite-${GCCVERSION}${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
# Special hack: I don't use SITE_SUBDIR & DIST_SUBDIR, and only pathces
#               will be placed to subdirectory
#               It allows to use main gcc sources from other ports.
PATCHFILES=	mingw/${PORTNAME}-${GCCVERSION}-${PATCHVERSION:S/./-/}-src.diff.gz
# Skip patching of bohem-gc, it is bug of patch's authors
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF gcc-3.4 for Windows cross-development

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

GCCVERSION=	3.4.1
PATCHVERSION=	20040711.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${GCCVERSION}

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--enable-languages=c,c++,f77,objc,java \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--enable-threads --disable-nls \
		--disable-win32-registry --disable-shared \
		--enable-sjlj-exceptions --enable-libgcj \
		--disable-java-awt --without-x \
		--enable-java-gc=boehm --disable-libgcj-debug \
		--enable-interpreter --enable-hash-synchronization \
		--without-newlib \
		--with-gxx-include-dir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include/c++/${GCCVERSION} \
		--infodir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info \
		--includedir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include \
		--datadir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/share
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
LIBTOOLFILES=	configure gcc/configure
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}g++.1 ${PKGNAMEPREFIX}g77.1 \
		${PKGNAMEPREFIX}gcj.1 ${PKGNAMEPREFIX}grepjar.1 ${PKGNAMEPREFIX}jar.1 \
		${PKGNAMEPREFIX}cpp.1 ${PKGNAMEPREFIX}gcov.1 ${PKGNAMEPREFIX}jcf-dump.1 \
		${PKGNAMEPREFIX}jv-convert.1 ${PKGNAMEPREFIX}jv-scan.1 ${PKGNAMEPREFIX}rmic.1 \
		${PKGNAMEPREFIX}rmiregistry.1 ${PKGNAMEPREFIX}gcjh.1 ${PKGNAMEPREFIX}gij.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCCVERSION}

INFO=		cpp cppinternals g77 gcc gccinstall gccint gcj
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

BINARIES=	gcc cpp g++ g77 gcov gcj gcjh jcf-dump jv-scan grepjar jar

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64 die to platform rename"
.endif

.if ${ARCH} == "alpha"
BROKEN=		"C++ could not be compiled on Alphas"
.endif

post-configure:
	@${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=\s*).+$$,\1libstdc++-v3 libf2c libobjc mingw,' ${WRKSRC}/Makefile
	@${PERL} -pi.bak -e 's,^(install-info:),\1\ndonot-\1,' ${WRKSRC}/gcc/Makefile

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.post.mk>
