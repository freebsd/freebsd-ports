# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	dmalloc
PORTVERSION=	5.5.2
CATEGORIES=	devel
# Version 5.5.2 is only available at this URL
MASTER_SITES=	http://dmalloc.com/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable debug memory allocation library

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads --enable-shlib --prefix="${STAGEDIR}${PREFIX}"
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_DATA}"
CFLAGS=		-fPIC
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	all heavy
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET+=installdocs
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|\.@shlibext@|\.@shlibext@.1|' ${WRKSRC}/Makefile.in

post-install:
	@(cd ${STAGEDIR}${PREFIX}/lib; \
		${STRIP_CMD} libdmalloc.so.1; \
		${LN} -sf libdmalloc.so.1 libdmalloc.so; \
		${STRIP_CMD} libdmallocxx.so.1; \
		${LN} -sf libdmallocxx.so.1 libdmallocxx.so; \
		${STRIP_CMD} libdmallocth.so.1; \
		${LN} -sf libdmallocth.so.1 libdmallocth.so; \
		${STRIP_CMD} libdmallocthcxx.so.1; \
		${LN} -sf libdmallocthcxx.so.1 libdmallocthcxx.so)

.include <bsd.port.mk>
