# New ports collection makefile for:	HP48-xgcc
# Date created:				20 Feb 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hp48xgcc
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/source/${PORTVERSION}:hp \
		ftp://ftp.gnu.org/old-gnu/gcc/:gcc
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:hp \
		gcc-${GCC_VER}.tar.gz:gcc
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU C cross-compiler for HP48 calculators

USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_ZIP=		yes

GCC_VER=	2.7.2
GCC_DIR=	${WRKDIR}/gcc-${GCC_VER}
PLIST_SUB+=	GCC_VER=${GCC_VER}
WRKSRC=		${WRKDIR}/saturn
ALL_TARGET=	default
INSTALL_TARGET=	build-lib
MAKE_ARGS=	GCC_SRC="${GCC_DIR}" GCC_VERSION="${GCC_VER}" \
		CFLAGS="${CFLAGS}" CLIB="" ROOT="${PREFIX}" \
		INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Configure fails on !i386
.endif

post-extract: .SILENT
# Extract GCC distribution separately because of USE_ZIP/.tar.gz conflict
	cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/gcc-${GCC_VER}.tar.gz | ${TAR} -xf -
# Patch GCC a bit
	cd ${GCC_DIR} && ${PATCH} -s < ${WRKSRC}/gcc-target/patches-${GCC_VER}
# Prepare GCC by creating proper config symlink
	${LN} -sf ../../saturn/gcc-target/config-saturn ${GCC_DIR}/config/saturn
# Allow GCC to build in our environment
	${REINPLACE_CMD} '178d' ${GCC_DIR}/gcc.c
# FreeBSD has vprintf() actually
	${CHMOD} +w ${GCC_DIR}/config/xm-freebsd.h
	${ECHO_CMD} '#define HAVE_VPRINTF' >> ${GCC_DIR}/config/xm-freebsd.h
# Do not install yet another copies of GPL
	${REINPLACE_CMD} '/COPYING/d' ${WRKSRC}/make.pubfiles

do-configure:
	cd ${GCC_DIR} && ./configure --target=saturn-local-hp48 \
		--prefix=${PREFIX}

.include <bsd.port.post.mk>
