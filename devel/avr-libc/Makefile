# New ports collection makefile for:	avr-libc
# Date created:		04 Dec 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc
PORTVERSION=	20020630
CATEGORIES=	devel
#MASTER_SITES=	http://www.amelek.gda.pl/avr/libc/
MASTER_SITES=	http://www.amelek.gda.pl/avr/test/ \
		http://www.enteract.com/~rneswold/avr/:libdoc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PDFDOC}:libdoc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	joerg@freebsd.org

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc \
		${GMAKE}:${PORTSDIR}/devel/gmake
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
CONFIGURE_SCRIPT= doconf

PDFDOC=		avr-tools.pdf

do-build:
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./domake MAKE=${GMAKE})

do-install:
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./domake MAKE=${GMAKE} install)
		${MKDIR} ${PREFIX}/share/doc/avr-libc
		${MKDIR} ${PREFIX}/share/doc/avr-libc/examples
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/LICENSE \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${WRKDIR}/${DISTNAME}/doc/register-usage.txt \
			${WRKDIR}/${DISTNAME}/doc/avr-libc-reference.html \
			${PREFIX}/share/doc/avr-libc
		@for f in avr-recv.c io.c prg printf.h progmem.c \
			send_byte.s signal.c;\
		do \
			${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/examples/$$f \
				${PREFIX}/share/doc/avr-libc/examples; \
		done
		${INSTALL_DATA} ${DISTDIR}/${PDFDOC} ${PREFIX}/share/doc/avr-libc/avr-tools.pdf

.include <bsd.port.mk>
