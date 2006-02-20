# New ports collection makefile for:	avr-libc
# Date created:		04 Dec 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc
PORTVERSION=	1.4.3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	joerg@freebsd.org
COMMENT=	A C and math library for the Atmel AVR controller family

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		latex:${PORTSDIR}/print/teTeX \
		pdflatex:${PORTSDIR}/print/teTeX \
		fig2dev:${PORTSDIR}/print/transfig
.endif

BROKEN=		Incomplete pkg-plist

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr \
	--enable-doc --disable-versioned-doc
PLIST_DOC=	${PKGDIR}/pkg-plist.doc
.else
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr
PLIST_DOC=
.endif
# Work around the braind***ness introduced by <bsd.cpu.mk> in freebsd-5.
# Sorry, the user is no longer be able to override the optimization and
# debugging settings now.
MAKE_ENV=	NO_CPU_CFLAGS=true
CFLAGS=		-O
CXXFLAGS=	-O

do-install:
		${RM} -f ${TMPPLIST}; ${CAT} ${PLIST_DOC} ${PLIST} > ${TMPPLIST}
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/LICENSE \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${PREFIX}/share/doc/avr-libc

.include <bsd.port.mk>
