# New ports collection makefile for:	avr-libc-devel
# Date created:		29 Oct 2007
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	avr-libc-devel
PORTVERSION=	1.5.1.20071029
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	avr-libc
DISTNAME=	avr-libc-${DISTVERSION}${DISTVERSIONSUFFIX}

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
		fig2dev:${PORTSDIR}/print/transfig \
		jpegtopnm:${PORTSDIR}/graphics/netpbm
.endif

DOCSDIR=	${PREFIX}/share/doc/avr-libc
USE_BZIP2=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFLICTS=	avr-libc-[1-9]*

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
		${RM} -f ${TMPPLIST}
.if !defined(NOPORTDOCS)
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
.else
		-${MKDIR} ${DOCSDIR}
.endif
		${CAT} ${PLIST} >> ${TMPPLIST}
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/LICENSE \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${DOCSDIR}

.include <bsd.port.mk>
