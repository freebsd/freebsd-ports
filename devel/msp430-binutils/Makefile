# New ports collection makefile for:	msp430-binutils
# Date created:		15 Oct 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	msp430-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	GNU binutils for TI's msp430 MCUs cross-development

BINUTILVERSION=	2.14

WRKSRC=		${WRKDIR}/${PORTNAME}-${BINUTILVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --infodir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info
USE_LIBTOOL=	yes
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

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip

INFO_NOAUTO=	bfd.info binutils.info as.info ld.info \
		standards.info configure.info

post-install:
.for F in ${BINARIES}
	@${STRIP_CMD} ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
.for F in ${INFO_NOAUTO}
	install-info ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info/${F} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
