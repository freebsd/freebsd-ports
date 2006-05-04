# New ports collection makefile for:	dmalloc
# Date created:			7 December 2000
# Whom:				Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$

PORTNAME=	dmalloc
PORTVERSION=	5.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dmalloc
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable debug memory allocation library

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-threads --enable-shlib
CFLAGS+=	-fPIC
INSTALLS_SHLIB=	yes

ALL_TARGET=	all heavy
INSTALL_TARGET=	install

INFO=	dmalloc

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=installdocs installinfo
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\.so|\.so.1|' ${WRKSRC}/Makefile.in

post-install:
	@(cd ${PREFIX}/lib; \
		${LN} -sf ${PREFIX}/lib/libdmalloc.so.1 ${PREFIX}/lib/libdmalloc.so; \
		${LN} -sf ${PREFIX}/lib/libdmallocxx.so.1 ${PREFIX}/lib/libdmallocxx.so; \
		${LN} -sf ${PREFIX}/lib/libdmallocth.so.1 ${PREFIX}/lib/libdmallocth.so; \
		${LN} -sf ${PREFIX}/lib/libdmallocthcxx.so.1 ${PREFIX}/lib/libdmallocthcxx.so)

.include <bsd.port.mk>
