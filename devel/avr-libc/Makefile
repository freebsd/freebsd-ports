# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avr-libc
PORTVERSION=	1.8.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	C and math library for the Atmel AVR controller family

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	avr-as:devel/avr-binutils \
		avr-ld:devel/avr-binutils \
		avr-gcc:devel/avr-gcc
RUN_DEPENDS=	avr-as:devel/avr-binutils \
		avr-ld:devel/avr-binutils \
		avr-gcc:devel/avr-gcc

OPTIONS_DEFINE=	DOXYGEN

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOXYGEN}
.undef WITHOUT_AVRLIBCDOCS=	true
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
USE_TEX=	latex:build
BUILD_DEPENDS+=	doxygen:devel/doxygen \
		fig2dev:print/transfig \
		jpegtopnm:graphics/netpbm \
		dvips:print/tex-dvipsk
.endif

USES=		gettext-tools tar:bzip2 gmake
HAS_CONFIGURE=	yes

CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
.if ${PORT_OPTIONS:MDOXYGEN}
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr \
	--enable-doc --disable-versioned-doc --prefix=${PREFIX} \
	--mandir=${PREFIX}/share/doc/avr-libc/man
PLIST_DOC=	${PKGDIR}/pkg-plist.doc
.else
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr --prefix=${PREFIX}
PLIST_DOC=
.endif
# Work around the braind***ness introduced by <bsd.cpu.mk> in freebsd-5.
# Sorry, the user is no longer be able to override the optimization and
# debugging settings now.
MAKE_ENV=	NO_CPU_CFLAGS=true
CFLAGS+=	-O
CXXFLAGS+=	-O

post-patch:
.if ! ${PORT_OPTIONS:MDOXYGEN}
	${REINPLACE_CMD} -e '/SUBDIRS/s,examples,,' ${WRKSRC}/doc/Makefile.in
.endif

do-install:
		${RM} -f ${TMPPLIST}
.if ${PORT_OPTIONS:MDOXYGEN}
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
	        @for file in ${PLIST_FILES}; do \
			${ECHO_CMD} $${file} >> ${TMPPLIST}; \
	        done
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
			${MAKE_CMD} ${MAKE_ARGS} install)
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AUTHORS \
			${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
