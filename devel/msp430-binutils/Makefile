# New ports collection makefile for:	msp430-binutils
# Date created:		15 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	msp430-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	GNU binutils for TI's msp430 MCUs cross-development

BROKEN=		Incomplete pkg-plist

BINUTILVERSION=	2.15

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --infodir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info
USE_INC_LIBTOOL_VER=	13
LIBTOOLFILES=	configure bfd/configure binutils/configure etc/configure \
		gas/configure gprof/configure ld/configure opcodes/configure
MAN1=		${PKGNAMEPREFIX}ar.1 ${PKGNAMEPREFIX}nm.1 \
		${PKGNAMEPREFIX}objdump.1 ${PKGNAMEPREFIX}ranlib.1 \
		${PKGNAMEPREFIX}size.1 ${PKGNAMEPREFIX}strings.1 \
		${PKGNAMEPREFIX}strip.1 ${PKGNAMEPREFIX}objcopy.1 \
		${PKGNAMEPREFIX}addr2line.1 ${PKGNAMEPREFIX}nlmconv.1 \
		${PKGNAMEPREFIX}c++filt.1 ${PKGNAMEPREFIX}as.1 \
		${PKGNAMEPREFIX}ld.1 ${PKGNAMEPREFIX}dlltool.1 \
		${PKGNAMEPREFIX}readelf.1 ${PKGNAMEPREFIX}windres.1

INFO=		bfd binutils standards configure as ld
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip

pre-configure:
	${CHMOD} 755 ${WRKSRC}/configure

post-install:
# Register these too
	install-info ${PREFIX}/${INFO_PATH}/configure.info ${PREFIX}/${INFO_PATH}/dir
	install-info ${PREFIX}/${INFO_PATH}/standards.info ${PREFIX}/${INFO_PATH}/dir
# This should go after all *.info stuff
	${ECHO} "@unexec rm %D/${PKGNAMEPREFIX:S/-$//}/info/dir" >> ${TMPPLIST}
	${ECHO} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//}/info 2> /dev/null || true" >> ${TMPPLIST}
	${ECHO} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>
