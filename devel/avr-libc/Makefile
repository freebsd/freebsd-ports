PORTNAME=	avr-libc
PORTVERSION=	2.1.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	C and math library for the Atmel AVR controller family
WWW=		https://savannah.nongnu.org/projects/avr-libc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	avr-as:devel/binutils@avr \
		avr-ld:devel/binutils@avr \
		avr-gcc:devel/avr-gcc
RUN_DEPENDS=	avr-as:devel/binutils@avr \
		avr-ld:devel/binutils@avr \
		avr-gcc:devel/avr-gcc

USES=		gettext-tools gmake tar:bzip2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--build=`./config.guess` --host=avr --prefix=${PREFIX}
CONFIGURE_ENV=	CC=avr-gcc PREFIX=${PREFIX}

OPTIONS_DEFINE=	DOXYGEN

DOXYGEN_BROKEN=	Build fails without showing any specific error while generating the documentation
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
		fig2dev:print/fig2dev \
		jpegtopnm:graphics/netpbm
DOXYGEN_USES=	tex
DOXYGEN_USE=	TEX=dvipsk:build,formats:build,latex:build
DOXYGEN_CONFIGURE_ON=	--enable-doc --disable-versioned-doc \
	--mandir=${PREFIX}/share/doc/avr-libc/man
DOXYGEN_VARS=	PLIST_DOC=${PKGDIR}/pkg-plist.doc

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOXYGEN}
.undef WITHOUT_AVRLIBCDOCS=	true
.endif

post-patch-DOXYGEN-off:
	${REINPLACE_CMD} -e '/SUBDIRS/s,examples,,' ${WRKSRC}/doc/Makefile.in

do-install:
	${RM} ${TMPPLIST}
	${CAT} ${PLIST} >> ${TMPPLIST}
	@for file in ${PLIST_FILES}; do \
		${ECHO_CMD} $${file} >> ${TMPPLIST}; \
	done
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} install)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/AUTHORS \
		${STAGEDIR}/${DOCSDIR}

do-install-DOXYGEN-on:
	(cd ${BUILD_WRKSRC}/doc/api/avr-libc-user-manual && \
		 ${FIND} . -type f \
		 \( -name '*.html' -or -name '*.css' -or \
		    -name '*.jpg' -or -name '*.png' \) |\
		 ${GREP} -v '/search/' |\
		 ${SORT} |\
		 ${SED} -e 's|^\.|share/doc/avr-libc/avr-libc-user-manual|' \
		 >> ${TMPPLIST})
	(cd ${BUILD_WRKSRC}/doc/api/man/man3 && \
		 ${FIND} . -type f |\
		 ${SORT} |\
		 ${SED} -e 's|^\.|share/doc/avr-libc/man/man3|' \
		 >> ${TMPPLIST})
	${CAT} ${PLIST_DOC} >> ${TMPPLIST}

.include <bsd.port.mk>
