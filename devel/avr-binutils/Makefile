# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	avr-

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	GNU binutils for Atmel AVR 8-bit RISC cross-development

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}

USES=		gmake tar:bzip2
CONFIGURE_ARGS=	--target=avr --disable-werror --disable-nls
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
.if (${MACHINE_ARCH} == "amd64")
MACHINE_ARCH=	x86_64
.endif

INFO=		as binutils gprof ld bfd standards configure
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

add-plist-post:
	@${ECHO_CMD} "@unexec rm %D/${INFO_PATH}/dir 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${INFO_PATH} 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${PKGNAMEPREFIX:S/-$//} 2> /dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
