# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hp48xgcc
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	SF/${PORTNAME}/source/${PORTVERSION} \
		ftp://ftp.gnu.org/old-gnu/gcc/:gcc
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gcc-${GCC_VER}.tar.gz:gcc
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU C cross-compiler for HP48 calculators

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386

USES=		gmake perl5 zip
USE_PERL5=	build

GCC_VER=	2.7.2
GCC_DIR=	${WRKDIR}/gcc-${GCC_VER}
PLIST_SUB=	GCC_VER=${GCC_VER}
WRKSRC=		${WRKDIR}/saturn
ALL_TARGET=	default
INSTALL_TARGET=	build-lib
MAKE_ARGS=	GCC_SRC="${GCC_DIR}" GCC_VERSION="${GCC_VER}" \
		CFLAGS="${CFLAGS}" CLIB="" ROOT="${STAGEDIR}${PREFIX}" \
		INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" LDXX="${CXX}"

post-extract: .SILENT
# Extract GCC distribution separately because of USE_ZIP/.tar.gz conflict
	${TAR} xzf ${_DISTDIR}/gcc-${GCC_VER}.tar.gz -C ${WRKDIR}
# Patch GCC a bit
	${PATCH} -d ${GCC_DIR} -s < ${WRKSRC}/gcc-target/patches-${GCC_VER}
# Prepare GCC by creating proper config symlink
	${LN} -sf ../../saturn/gcc-target/config-saturn ${GCC_DIR}/config/saturn
# Allow GCC to build in our environment
	${REINPLACE_CMD} -e '178d' ${GCC_DIR}/gcc.c
# FreeBSD has vprintf() actually
	${CHMOD} +w ${GCC_DIR}/config/xm-freebsd.h
	${ECHO_CMD} '#define HAVE_VPRINTF' >> ${GCC_DIR}/config/xm-freebsd.h
# Do not install extra copies of GPL (we use license framework instead)
	${REINPLACE_CMD} -e '/COPYING/d' ${WRKSRC}/make.pubfiles

do-configure:
	cd ${GCC_DIR} && ./configure --target=saturn-local-hp48 \
		--prefix=${PREFIX}

.include <bsd.port.mk>
