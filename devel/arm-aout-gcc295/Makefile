# ex:ts=8
# New ports collection makefile for:	armgcc-2.95.2
# Date created:		22 Aug 2000
# Whom:			Paul Becke <pbecke@javagear.com>
#
# $FreeBSD$
#

PORTNAME=	arm-aout-gcc295
PORTVERSION=	2.95.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gcc/releases/${DISTNAME}
DISTNAME=	gcc-2.95.2

MAINTAINER=	pbecke@javagear.com

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - -T ${FILESDIR}/tlist -X ${FILESDIR}/xlist

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=arm-aout --with-gnu-as --with-gnu-ld --with-newlib
MAKE_FLAGS=	LANGUAGES="c c++"
MAN1=		arm-aout-addr2line.1 arm-aout-ar.1 arm-aout-as.1	\
		arm-aout-c++filt.1 arm-aout-ld.1 arm-aout-nlmconv.1	\
		arm-aout-nm.1 arm-aout-objcopy.1 arm-aout-objdump.1	\
		arm-aout-ranlib.1 arm-aout-size.1 arm-aout-strings.1	\
		arm-aout-strip.1

post-extract:
	${MKDIR} ${WRKSRC}/gcc/target
	${LN} -s ${FILESDIR}/include ${WRKSRC}/gcc/target/include

do-configure:
	cd ${WRKSRC}/libiberty ; ./configure ${CONFIGURE_ARGS}
	cd ${WRKSRC}/gcc ; ./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/libiberty ; ${GMAKE}
	cd ${WRKSRC}/gcc ; ${GMAKE}

do-install:
	cd ${WRKSRC}/gcc ; ${GMAKE} install
	${LN} -f ${PREFIX}/bin/arm-aout-g++ ${PREFIX}/arm-aout/bin/g++
	${LN} -f ${PREFIX}/bin/arm-aout-c++filt ${PREFIX}/arm-aout/bin/c++filt
	cd ${PREFIX}/lib ; ${MV} -f libbfd.* libiberty.* libopcodes.*  \
		${PREFIX}/lib/gcc-lib/arm-aout/${PORTVERSION}

.include <bsd.port.mk>
