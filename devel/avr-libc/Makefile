# New ports collection makefile for:	avr-libc
# Date created:		04 Dec 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc
PORTVERSION=	2003.09.09
PORTREVISION=	1
CATEGORIES=	devel
# Currently still snapshots, not yet officially released again.
#MASTER_SITES=	${MASTER_SITE_SAVANNAH}
#MASTER_SITE_SUBDIR=	${PORTNAME}
MASTER_SITES=	http://people.freebsd.org/~joerg/

MAINTAINER=	joerg@freebsd.org
COMMENT=	A C and math library for the Atmel AVR controller family

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc \
		${GMAKE}:${PORTSDIR}/devel/gmake
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		latex:${PORTSDIR}/print/teTeX \
		fig2dev:${PORTSDIR}/print/transfig
.endif

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
CONFIGURE_SCRIPT= doconf
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS=	--enable-doc --disable-versioned-doc
.endif
# Work around the braind***ness introduced by <bsd.cpu.mk> in freebsd-5.
# Sorry, the user is no longer be able to override the optimization and
# debugging settings now.
MAKE_ENV=	NO_CPU_CFLAGS=true
CFLAGS=		-O
CXXFLAGS=	-O

DEMOFILES=	Makefile demo.c
.if !defined(NOPORTDOCS)
DEMOFILES+=	demo.bin demo.hex demo.pdf demo.srec
.endif

do-build:
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./domake MAKE=${GMAKE})

do-install:
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./domake MAKE=${GMAKE} install)
		${MKDIR} ${PREFIX}/share/doc/avr-libc
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples/demo
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples/twitest
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/LICENSE \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${PREFIX}/share/doc/avr-libc
		@for f in avr-recv.c io.c prg printf.h progmem.c \
			send_byte.s signal.c;\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/$$f \
				${PREFIX}/share/doc/avr-libc/examples; \
		done
		@for f in ${DEMOFILES};\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/demo/$$f \
				${PREFIX}/share/doc/avr-libc/examples/demo; \
		done
		@for f in Makefile twitest.c;\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/twitest/$$f \
				${PREFIX}/share/doc/avr-libc/examples/twitest; \
		done

.include <bsd.port.mk>
