# Created by: Joerg Wunsch <joerg@freebsd.org>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.20.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	avr-

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	GNU binutils for Atmel AVR 8-bit RISC cross-development

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}

USE_BZIP2=	yes
USE_GCC=	any
USES=		gmake
CONFIGURE_ARGS=	--target=avr --disable-werror --disable-nls
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
.if (${MACHINE_ARCH} == "amd64")
MACHINE_ARCH=	x86_64
.endif

MAN1=	\
		avr-addr2line.1 \
		avr-ar.1 \
		avr-as.1 \
		avr-c++filt.1 \
		avr-dlltool.1 \
		avr-gprof.1 \
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
		avr-windmc.1 \
		avr-windres.1
INFO=		as binutils gprof ld bfd standards configure
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

add-plist-post:
	@${ECHO_CMD} "@unexec rm %D/${INFO_PATH}/dir 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${INFO_PATH} 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
