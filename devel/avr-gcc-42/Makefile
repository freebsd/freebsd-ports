# New ports collection makefile for:	avr-gcc-42
# Date created:		17 Jun 2009
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gcc-42
PORTVERSION=	4.2.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITES+=	http://people.freebsd.org/~joerg/:local
MASTER_SITE_SUBDIR=	releases/gcc-${PORTVERSION}
PKGNAMEPREFIX=	avr-
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joerg@freebsd.org
COMMENT=	FSF GCC 4.2.x for Atmel AVR 8-bit RISC cross-development

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils

# GCC 4.x doesn't want to be built in its own source directory.
WRKSRC=			${WRKDIR}/gcc-${PORTVERSION}
BUILD_WRKSRC=		${WRKDIR}/build
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}
CONFIGURE_SCRIPT=	../gcc-${PORTVERSION}/configure
NO_LATEST_LINK=	Use devel/avr-gcc for a stable version.

USE_PERL5_BUILD=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

CONFLICTS=	avr-gcc-3* avr-gcc-4.*

CONFIGURE_ARGS=	--target=avr --disable-libssp

MAKE_FLAGS=	LANGUAGES="c c++"
# get rid of that silly -mcpu=pentiumpro FreeBSD 5+ is so fond of. :-(
MAKE_ENV=	MACHINE_ARCH=avr

MAN1=		avr-cpp.1 avr-gcc.1 avr-g++.1 avr-gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp gcc gccint cppinternals gccinstall

post-extract:
	cd ${WRKDIR} && ${MKDIR} build

.include <bsd.port.post.mk>
