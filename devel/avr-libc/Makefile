# New ports collection makefile for:	avr-libc
# Date created:		04 Dec 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc
PORTVERSION=	2002.11.24
CATEGORIES=	devel
# There are currently no official master sites for it.  Everything is
# in savannah.gnu.org's CVS only.
#MASTER_SITES=	http://www.amelek.gda.pl/avr/libc/
MASTER_SITES=	http://people.freebsd.org/~joerg/

MAINTAINER=	joerg@freebsd.org

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc \
		${GMAKE}:${PORTSDIR}/devel/gmake \
		doxygen:${PORTSDIR}/devel/doxygen \
		latex:${PORTSDIR}/print/teTeX \
		fig2dev:${PORTSDIR}/print/transfig
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
CONFIGURE_SCRIPT= doconf
CONFIGURE_ARGS=	--enable-doc --disable-versioned-doc
# Work around the braind*** introduced by <bsd.cpu.mk> in freebsd-current.
MAKE_ENV=	NO_CPU_CFLAGS=true

do-build:
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./domake MAKE=${GMAKE})

do-install:
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./domake MAKE=${GMAKE} install)
		${MKDIR} ${PREFIX}/share/doc/avr-libc
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples/demo
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/LICENSE \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${WRKDIR}/${DISTNAME}/doc/avr-libc-reference.html \
			${PREFIX}/share/doc/avr-libc
		@for f in avr-recv.c io.c prg printf.h progmem.c \
			send_byte.s signal.c;\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/$$f \
				${PREFIX}/share/doc/avr-libc/examples; \
		done
		@for f in Makefile demo.bin demo.c demo.hex demo.pdf \
			demo.srec;\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/demo/$$f \
				${PREFIX}/share/doc/avr-libc/examples/demo; \
		done

.include <bsd.port.mk>
