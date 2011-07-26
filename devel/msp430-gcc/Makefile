# New ports collection makefile for:	msp430-gcc
# Date created:		15 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}.${MSPGCCVERSION}
PORTEPOCH=	2
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${GCCVERSION}
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} \
		SF/mspgcc/mspgcc:mspgcc
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	msp430-
DISTFILES=	${PORTNAME}-core-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-g++-${GCCVERSION}${EXTRACT_SUFX} \
		mspgcc-${MSPGCCVERSION}${EXTRACT_SUFX}:mspgcc

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF gcc-4.5 for TI's msp430 MCUs cross-development
LICENSE=	GPLv3

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		${PKGNAMEPREFIX}ld:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		mpfr.4:${PORTSDIR}/math/mpfr \
		mpc.2:${PORTSDIR}/math/mpc

CONFLICTS=	msp430-gcc-3.*

GCCVERSION=	4.5.3
MSPGCCVERSION=	20110716
PATCHVERSION=	20110706

SRCDIR=         ${WRKDIR}/${PORTNAME}-${GCCVERSION}
WRKSRC=         ${WRKDIR}/build
PATCH_WRKSRC=	${SRCDIR}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_ICONV=	yes
USE_PERL5_BUILD=yes
MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../${SRCDIR:S/${WRKDIR}\///}/configure
CONFIGURE_ARGS+=--target=${PKGNAMEPREFIX:S/-$//} \
		--enable-languages=c,c++ \
		--with-gmp=${LOCALBASE} --with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} --with-libiconv-prefix=${LOCALBASE} \
		--with-system-zlib --disable-nls \
		--with-pkgversion="MSPGCC_${MSPGCCVERSION}"
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}g++.1 \
		${PKGNAMEPREFIX}cpp.1 ${PKGNAMEPREFIX}gcov.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCCVERSION}

INFO=		cpp cppinternals gcc gccinstall gccint
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

BINARIES=	gcc gcc-${GCCVERSION} c++ g++ gcov cpp

.include <bsd.port.pre.mk>

pre-patch:
	@cd ${SRCDIR} && ${PATCH} -s -p1 < ../mspgcc-${MSPGCCVERSION}/${PKGNAMEPREFIX}${PORTNAME}-${GCCVERSION}-${PATCHVERSION}.patch

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
