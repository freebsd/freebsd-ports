# ex:ts=8
# New ports collection makefile for:	binutils-arm
# Date created:		3 November 2000
# Whom:			Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	arm-elf-

MAINTAINER=	esk@ira.uka.de

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=arm-elf
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure bfd/configure binutils/configure etc/configure \
		gas/configure gprof/configure intl/configure ld/configure \
		libiberty/configure opcodes/configure
MAN1=		arm-elf-ar.1 arm-elf-nm.1 arm-elf-objdump.1 arm-elf-ranlib.1 \
		arm-elf-size.1 arm-elf-strings.1 arm-elf-strip.1 \
		arm-elf-objcopy.1 arm-elf-addr2line.1 arm-elf-nlmconv.1 \
		arm-elf-c++filt.1 arm-elf-as.1 arm-elf-ld.1

post-install:
.for F in addr2line c++filt gasp objcopy objdump readelf size strings
	${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F  \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
	cd ${PREFIX}/lib ; ${MV} libbfd.a libiberty.a libopcodes.a \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib
	${MKDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include
	cd ${PREFIX}/include ; ${MV} ansidecl.h bfd.h bfdlink.h  \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include

.include <bsd.port.mk>
