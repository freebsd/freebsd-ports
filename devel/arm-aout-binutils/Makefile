# ex:ts=8
# New ports collection makefile for:	armbinutils-2.9.1
# Date created:		2 june 2000
# Whom:			Paul Becke <pbecke@javagear.com>
#
# $FreeBSD$
#

PORTNAME=	arm-aout-binutils
PORTVERSION=	2.9.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils
DISTNAME=	binutils-2.9.1

MAINTAINER=	pbecke@javagear.com

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=arm-aout
MAN1=	arm-aout-addr2line.1 arm-aout-ar.1 arm-aout-as.1	\
	arm-aout-c++filt.1 arm-aout-ld.1 arm-aout-nlmconv.1	\
	arm-aout-nm.1 arm-aout-objcopy.1 arm-aout-objdump.1	\
	arm-aout-ranlib.1 arm-aout-size.1 arm-aout-strings.1	\
	arm-aout-strip.1

.include <bsd.port.mk>
