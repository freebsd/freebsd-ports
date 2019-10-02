# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	dmalloc
PORTVERSION=	5.5.2
PORTREVISION=	1
CATEGORIES=	devel
# Version 5.5.2 is only available at this URL
MASTER_SITES=	http://dmalloc.com/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Portable debug memory allocation library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads --enable-shlib
GNU_CONFIGURE_PREFIX=	"${STAGEDIR}${PREFIX}"
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL_DATA}"
CFLAGS=		-fPIC
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	all heavy
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS

DOCS_INSTALL_TARGET=	installdocs

post-install:
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/dmalloc
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dmalloc
	@(cd ${STAGEDIR}${PREFIX}/lib; \
		${CHMOD} 644 libdmalloc.so.1; \
		${STRIP_CMD} libdmalloc.so.1; \
		${LN} -sf libdmalloc.so.1 libdmalloc.so; \
		${CHMOD} 644 libdmallocxx.so.1; \
		${STRIP_CMD} libdmallocxx.so.1; \
		${LN} -sf libdmallocxx.so.1 libdmallocxx.so; \
		${CHMOD} 644 libdmallocth.so.1; \
		${STRIP_CMD} libdmallocth.so.1; \
		${LN} -sf libdmallocth.so.1 libdmallocth.so; \
		${CHMOD} 644 libdmallocthcxx.so.1; \
		${STRIP_CMD} libdmallocthcxx.so.1; \
		${LN} -sf libdmallocthcxx.so.1 libdmallocthcxx.so)

.include <bsd.port.mk>
