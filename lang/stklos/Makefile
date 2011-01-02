# New ports collection makefile for:	STklos
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	stklos
PORTVERSION=	1.01
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.stklos.net/download/ \
		ftp://kaolin.essi.fr/pub/STklos/

MAINTAINER=	vmagerya@gmail.com
COMMENT=	The successor of the STk Scheme interpreter

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		pcre.0:${PORTSDIR}/devel/pcre \
		ffi.5:${PORTSDIR}/devel/libffi \
		gc.1:${PORTSDIR}/devel/boehm-gc-threaded

ONLY_FOR_ARCHS=	i386 amd64

USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="${PORTVERSION}"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads=posix

MAN1=		stklos-compile.1 stklos-config.1 stklos-genlex.1 \
		stklos-pkg.1 stklos.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lgc|-lgc-threaded|' \
		-e 's|bdw-gc|bdw-gc-threaded|' \
		-e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		-e 's|-@VERSION@||' \
		-e 's|^man_MANS = |man_MANS = stklos-pkg.1 |' \
		${WRKSRC}/doc/Makefile.in

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/^(install-data-am:).*/\1 install-man install-schemeDATA/' \
		-e '/install-docpdfDATA install-man install-schemeDATA/d' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
