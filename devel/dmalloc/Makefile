# New ports collection makefile for:	dmalloc
# Date created:			7 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	dmalloc
PORTVERSION=	4.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dmalloc
EXTRACT_SUFX=	.tgz

# Original from: Gray Watson http://256.com/gray/email.html
MAINTAINER=	jeremy@external.org

INSTALLS_SHLIB=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-threads --enable-shlib

# NOTE: we make the test program first because otherwise it screws up
# and tried to use the .so instead of the .a for some stupid reason
ALL_TARGET=	dmalloc_t all light

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmalloc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dmalloc.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libdmallocthcxx.so ${PREFIX}/lib/libdmallocthcxx.so.1
	@${LN} -sf ${PREFIX}/lib/libdmallocthcxx.so.1 ${PREFIX}/lib/libdmallocthcxx.so
	${INSTALL_DATA} ${WRKSRC}/libdmallocthcxx.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdmallocth.so ${PREFIX}/lib/libdmallocth.so.1
	@${LN} -sf ${PREFIX}/lib/libdmallocth.so.1 ${PREFIX}/lib/libdmallocth.so
	${INSTALL_DATA} ${WRKSRC}/libdmallocth.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdmalloc.so ${PREFIX}/lib/libdmalloc.so.1
	@${LN} -sf ${PREFIX}/lib/libdmalloc.so.1 ${PREFIX}/lib/libdmalloc.so
	${INSTALL_DATA} ${WRKSRC}/libdmalloc.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libdmalloclp.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dmalloc
	${INSTALL_DATA} ${WRKSRC}/dmalloc.html ${PREFIX}/share/doc/dmalloc
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/dmalloc.info ${PREFIX}/info
	@install-info ${PREFIX}/info/dmalloc.info ${PREFIX}/info/dir

.include <bsd.port.mk>
