# New ports collection makefile for:	mipsel-linux-binutils
# Date created:		13 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils
PKGNAMEPREFIX=	mipsel-linux-

MAINTAINER=	lev@serebryakov.spb.ru

PATCH_STRIP=	-p1
USE_GMAKE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//}
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure bfd/configure binutils/configure etc/configure \
		gas/configure gprof/configure ld/configure opcodes/configure
MAN1=		${PKGNAMEPREFIX}ar.1 ${PKGNAMEPREFIX}nm.1 \
		${PKGNAMEPREFIX}objdump.1 \
		${PKGNAMEPREFIX}ranlib.1 ${PKGNAMEPREFIX}size.1 \
		${PKGNAMEPREFIX}strings.1 ${PKGNAMEPREFIX}strip.1 \
		${PKGNAMEPREFIX}objcopy.1 ${PKGNAMEPREFIX}addr2line.1 \
		${PKGNAMEPREFIX}nlmconv.1 ${PKGNAMEPREFIX}c++filt.1 \
		${PKGNAMEPREFIX}as.1 ${PKGNAMEPREFIX}ld.1

PLIST_SUB+=	BINUTILS_TARG=${PKGNAMEPREFIX:S/-$//}

BINARIES=	addr2line ar as c++filt gasp ld nm objcopy objdump ranlib \
		size strings strip

post-install:
.for F in ${BINARIES}
	@strip ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
	@${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib
	@cd ${PREFIX}/lib ; ${MV} libiberty.a \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib
	@cd ${PREFIX}/lib ; ${MV} lib${PKGNAMEPREFIX}bfd.a \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib/libbfd.a
	@cd ${PREFIX}/lib ; ${MV} lib${PKGNAMEPREFIX}opcodes.a \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib/libopcodes.a
	@${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include
	@cd ${PREFIX}/include ; ${MV} ansidecl.h bfd.h bfdlink.h  \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include
	@for F in ${PREFIX}/info/as.info* ${PREFIX}/info/bfd.info* \
		${PREFIX}/info/binutils.info* ${PREFIX}/info/ld.info* \
		${PREFIX}/info/gasp.info*; do \
		${MV} $${F} `echo $${F} | ${SED} 's|info/|info/mipsel-linux-|'`; \
	done

.include <bsd.port.mk>
