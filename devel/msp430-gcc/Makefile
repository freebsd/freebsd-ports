# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}.${LTSVERSION}
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		SF/mspgcc/mspgcc:mspgcc
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	msp430-
DISTNAME=	${PORTNAME}-${GCCVERSION}
DISTFILES=	${PORTNAME}-core-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-g++-${GCCVERSION}${EXTRACT_SUFX} \
		mspgcc-${LTSVERSION}${EXTRACT_SUFX}:mspgcc

PATCH_SITES=		${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	mspgcc/Patches/LTS/${LTSVERSION}
PATCHFILES=		${LTS_PATCHES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF GCC 4.6 for TI's msp430 MCUs cross-development

LICENSE=	GPLv3

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc

CONFLICTS=	msp430-gcc-3.*

GCCVERSION=	4.6.3
LTSVERSION=	20120406
PATCHVERSION=	20120406
BUGS_FIXED=	3540953 3559978
LTS_PATCHES!=	for bugid in ${BUGS_FIXED} ; do echo ${PKGNAMEPREFIX}${PORTNAME}-${GCCVERSION}-${PATCHVERSION}-sf$${bugid}.patch ; done

SRCDIR=		${WRKDIR}/${PORTNAME}-${GCCVERSION}
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${SRCDIR}

USE_BZIP2=	yes
USES=		bison iconv gmake perl5
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../${SRCDIR:S/${WRKDIR}\///}/configure
CONFIGURE_ARGS+=--target=${PKGNAMEPREFIX:S/-$//} \
		--enable-languages=c,c++ \
		--enable-lto \
		--with-gmp=${LOCALBASE} --with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} ${ICONV_CONFIGURE_ARG} \
		--with-system-zlib --disable-nls \
		--with-pkgversion="MSPGCC_${LTSVERSION}"
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}g++.1 \
		${PKGNAMEPREFIX}cpp.1 ${PKGNAMEPREFIX}gcov.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCCVERSION}

INFO=		cpp cppinternals gcc gccinstall gccint libquadmath
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

BINARIES=	gcc gcc-${GCCVERSION} c++ g++ gcov cpp

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

pre-patch:
	@cd ${SRCDIR} && ${PATCH} -s -p1 < ../mspgcc-${LTSVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${GCCVERSION}-${PATCHVERSION}.patch

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-configure:
	@${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=).+$$,\1,' ${WRKSRC}/Makefile

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.post.mk>
