# Ports collection makefile for:  skyeye
# Date created:			  Mon July 18, 2005
# Whom:				  Ruan Wei (iamayan@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	skyeye
PORTVERSION=	0.9.5
CATEGORIES=	emulators
MASTER_SITES=	http://download.gro.clinux.org/skyeye/

MAINTAINER=	iamayan@gmail.com
COMMENT=	An environment simulates typical ARM-base embedded computer systems

BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20

WRKSRC=		${WRKDIR}/skyeye

MAN1=		arm-elf-gdb.1 arm-elf-run.1
INFO=		mmalloc

ONLY_FOR_ARCHS=	i386

SKYEYETARGET?=	arm-elf
CONFIGURE_TARGET=	--target=${SKYEYETARGET}
CONFIGURE_ARGS+=	--without-gtk-prefix \
			--without-gtk-exec-prefix \
			--disable-gtktest

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile"
.endif

.include <bsd.port.post.mk>
