# New ports collection makefile for:	avr-gcc
# Date created:		30 Nov 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	020701
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
#MASTER_SITE_SUBDIR=	binutils/releases
# old snapshots are deleted too frequently here :(
#MASTER_SITES=	ftp://sources.redhat.com/%SUBDIR%/
#MASTER_SITE_SUBDIR=	pub/binutils/snapshots
MASTER_SITES=	http://people.freebsd.org/~joerg/
PKGNAMEPREFIX=	avr-

MAINTAINER=	joerg@freebsd.org

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--target=avr
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure bfd/configure binutils/configure etc/configure \
		gas/configure gprof/configure intl/configure ld/configure \
		libiberty/configure opcodes/configure

MAN1=	\
		avr-addr2line.1 \
		avr-ar.1 \
		avr-as.1 \
		avr-c++filt.1 \
		avr-dlltool.1 \
		avr-ld.1 \
		avr-nlmconv.1 \
		avr-nm.1 \
		avr-objcopy.1 \
		avr-objdump.1 \
		avr-ranlib.1 \
		avr-readelf.1 \
		avr-size.1 \
		avr-strings.1 \
		avr-strip.1 \
		avr-windres.1

.include <bsd.port.mk>
