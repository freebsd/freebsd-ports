# New ports collection makefile for:	dmalloc
# Date created:			7 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	dmalloc
PORTVERSION=	5.5.2
CATEGORIES=	devel
# Version 5.5.2 is only available at this URL
MASTER_SITES=	http://dmalloc.com/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable debug memory allocation library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads --enable-shlib
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

ALL_TARGET=	all heavy
INSTALL_TARGET=	install

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=installdocs
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|\.@shlibext@|\.@shlibext@.1|' ${WRKSRC}/Makefile.in

post-install:
	@(cd ${PREFIX}/lib; \
		${LN} -sf ${PREFIX}/lib/libdmalloc.so.1 ${PREFIX}/lib/libdmalloc.so; \
		${LN} -sf ${PREFIX}/lib/libdmallocxx.so.1 ${PREFIX}/lib/libdmallocxx.so; \
		${LN} -sf ${PREFIX}/lib/libdmallocth.so.1 ${PREFIX}/lib/libdmallocth.so; \
		${LN} -sf ${PREFIX}/lib/libdmallocthcxx.so.1 ${PREFIX}/lib/libdmallocthcxx.so)

.include <bsd.port.mk>
