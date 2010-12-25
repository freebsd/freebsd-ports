# New ports collection makefile for:   avr-libc
# Date created:                04 Dec 2000
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc
PORTVERSION=	1.7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A C and math library for the Atmel AVR controller family

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc

.if !defined(NOPORTDOCS)
OPTIONS=	AVRLIBCDOCS "Build avr-libc documents" off
.endif

.include <bsd.port.options.mk>

.if defined(WITHOUT_AVRLIBCDOCS) || defined(NOPORTDOCS)
WITHOUT_AVRLIBCDOCS=	true
.undef WITH_AVRLIBCDOCS
.else
BROKEN=		does not build with AVRLIBCDOCS enabled
.endif

.if defined(WITH_AVRLIBCDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		latex:${PORTSDIR}/print/teTeX \
		pdflatex:${PORTSDIR}/print/teTeX \
		fig2dev:${PORTSDIR}/print/transfig \
		jpegtopnm:${PORTSDIR}/graphics/netpbm
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFLICTS=	avr-libc-devel*

CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
.if defined(WITH_AVRLIBCDOCS)
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr \
	--enable-doc --disable-versioned-doc --prefix=${PREFIX}
PLIST_DOC=	${PKGDIR}/pkg-plist.doc
.else
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr --prefix=${PREFIX}
PLIST_DOC=
.endif
# Work around the braind***ness introduced by <bsd.cpu.mk> in freebsd-5.
# Sorry, the user is no longer be able to override the optimization and
# debugging settings now.
MAKE_ENV=	NO_CPU_CFLAGS=true
CFLAGS=		-O
CXXFLAGS=	-O

post-patch:
.if defined(WITHOUT_AVRLIBCDOCS)
	${REINPLACE_CMD} -e '/SUBDIRS/s,examples,,' ${WRKSRC}/doc/Makefile.in
.endif

do-install:
		${RM} -f ${TMPPLIST}
.if defined(WITH_AVRLIBCDOCS)
		(cd ${BUILD_WRKSRC}/doc/api/avr-libc-user-manual && \
		 ${FIND} . -type f \
		  \( -name '*.html' -or -name '*.css' -or \
		     -name '*.jpg' -or -name '*.png' \) |\
		 ${SORT} |\
		 ${SED} -e 's|^\.|share/doc/avr-libc/avr-libc-user-manual|' \
		 >> ${TMPPLIST})
		(cd ${BUILD_WRKSRC}/doc/api/man/man3 && \
		 ${FIND} . -type f |\
		 ${SORT} |\
		 ${SED} -e 's|^\.|share/doc/avr-libc/man/man3|' \
		 >> ${TMPPLIST})
		${CAT} ${PLIST_DOC} >> ${TMPPLIST}
.endif
		${CAT} ${PLIST} >> ${TMPPLIST}
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
		-${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/LICENSE \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${DOCSDIR}

.include <bsd.port.mk>
