# Created by: Joerg Wunsch <joerg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	avr-libc
PORTVERSION=	1.8.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	C and math library for the Atmel AVR controller family

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc
RUN_DEPENDS=	avr-as:${PORTSDIR}/devel/avr-binutils \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		avr-gcc:${PORTSDIR}/devel/avr-gcc

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
.undef WITHOUT_AVRLIBCDOCS=	true
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		fig2dev:${PORTSDIR}/print/transfig \
		jpegtopnm:${PORTSDIR}/graphics/netpbm
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		gettext:build
HAS_CONFIGURE=	yes

CONFLICTS=	avr-libc-devel-[0-9]*

CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}
.if ${PORT_OPTIONS:MDOCS}
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
CFLAGS=		-O
CXXFLAGS=	-O

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/SUBDIRS/s,examples,,' ${WRKSRC}/doc/Makefile.in
.endif

do-install:
		${RM} -f ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
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
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} install)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/AUTHORS \
			${DOCSDIR}

.include <bsd.port.mk>
