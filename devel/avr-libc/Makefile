# New ports collection makefile for:	avr-libc
# Date created:		04 Dec 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc
PORTVERSION=	20010717
CATEGORIES=	devel
MASTER_SITES=	http://www.amelek.gda.pl/avr/libc/

MAINTAINER=	joerg@freebsd.org

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes

MAKE_FLAGS=	prefix=${PREFIX}

post-install:
		${MKDIR} ${PREFIX}/share/doc/avr-libc
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/doc/LICENSE \
			${WRKDIR}/${DISTNAME}/doc/register-usage.txt \
			${PREFIX}/share/doc/avr-libc
		@for f in avr-recv.c io.c prg printf.h progmem.c \
			send_byte.s signal.c;\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/$$f \
				${PREFIX}/share/doc/avr-libc/examples; \
		done
		${INSTALL_DATA} ${FILESDIR}/avr-lib.pdf ${PREFIX}/share/doc/avr-libc

.include <bsd.port.mk>
