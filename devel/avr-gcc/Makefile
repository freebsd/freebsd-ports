# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.5.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITES+=	http://people.freebsd.org/~joerg/:local
MASTER_SITE_SUBDIR=	releases/${DISTNAME}
PKGNAMEPREFIX=	avr-
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	FSF GCC 4.x for Atmel AVR 8-bit RISC cross-development

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils
LIB_DEPENDS=	libmpfr.so:${PORTSDIR}/math/mpfr \
		libgmp.so:${PORTSDIR}/math/gmp \
		libmpc.so:${PORTSDIR}/math/mpc
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils

# GCC 4.x doesn't want to be built in its own source directory.
WRKSRC=			${WRKDIR}/gcc-${PORTVERSION}
BUILD_WRKSRC=		${WRKDIR}/build
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
INSTALL_WRKSRC=		${BUILD_WRKSRC}
CONFIGURE_SCRIPT=	../gcc-${PORTVERSION}/configure

USE_PERL5=	build
USE_BZIP2=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
USES=		bison gettext gmake perl5
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

CONFLICTS=	avr-gcc-3* avr-gcc-42*

CONFIGURE_ARGS=	--target=avr --disable-libssp --with-gmp=${LOCALBASE}

MAKE_FLAGS=	LANGUAGES="c c++"

WITHOUT_CPU_CFLAGS=This is a cross-compiler.

MAN1=		avr-cpp.1 avr-gcc.1 avr-g++.1 avr-gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp gcc gccint cppinternals gccinstall

post-extract:
	cd ${WRKDIR} && ${MKDIR} build

.include <bsd.port.post.mk>
