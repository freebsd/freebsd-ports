# Ports collection makefile for:	simulavr
# Date created:				3 Sep 2002
# Whom:					Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	simulavr
PORTVERSION=	0.1.2
PORTREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
# special name only this time, don't let this go into ${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.6

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A simulator for AVR microcontrollers

BUILD_DEPENDS=	${LOCALBASE}/avr/include/avr/io.h:${PORTSDIR}/devel/avr-libc \
		avr-ld:${PORTSDIR}/devel/avr-binutils \
		doxygen:${PORTSDIR}/devel/doxygen \
		latex:${PORTSDIR}/print/teTeX

#USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-versioned-doc --enable-pdf

MAN1=		simulavr.1 simulavr-disp.1
INFO=		simulavr

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
.if ${OSVERSION} >= 700042
BROKEN=		Does not compile
.endif
.endif

do-install:
		${RM} -f ${TMPPLIST}
		(cd ${BUILD_WRKSRC}/doc/internals_html && \
		 ${FIND} . -type f \( -name '*.html' -or -name '*.css' \) |\
		${SORT} |\
		${SED} -e 's|^\.|share/doc/simulavr/internals_html|' \
		>> ${TMPPLIST})
		${CAT} ${PLIST} >> ${TMPPLIST}
		@for man in ${__MANPAGES}; do \
			${ECHO_CMD} $${man} >> ${TMPPLIST}; \
		done
		(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} install)

.include <bsd.port.post.mk>
