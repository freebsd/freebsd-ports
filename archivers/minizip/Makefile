# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	minizip
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SF/libpng/zlib/${PORTVERSION}
DISTNAME=	zlib-${PORTVERSION}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Zip library and programs from Zlib distribution

LICENSE=	ZLIB

USES=		libtool pathfix tar:xz
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	-a -c -f
CONFIGURE_ARGS=	--enable-demos
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/zlib-${PORTVERSION}/contrib/minizip

.include <bsd.port.options.mk>

# work around missing typedef in 8.X's libz configuration
.if ${OSVERSION} < 900000
CPPFLAGS+=	-Dz_crc_t=uint32_t
.endif

post-patch:
	@${REINPLACE_CMD} 's/#ifdef unix || __APPLE__/#ifdef unix/' ${WRKSRC}/mini???.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1

regression-test:
	${RM} -rf ${WRKDIR}/regression-test1
	${MKDIR} ${WRKDIR}/regression-test1
	${MV} ${WRKSRC}/*.[cho] ${WRKDIR}/regression-test1
	${RM} -f ${WRKDIR}/test.zip
	(cd ${WRKDIR}/regression-test1 && ${WRKSRC}/minizip ${WRKDIR}/test.zip *)
	${RM} -rf ${WRKDIR}/regression-test2
	${MKDIR} ${WRKDIR}/regression-test2
	${WRKSRC}/miniunzip ${WRKDIR}/test.zip -d ${WRKDIR}/regression-test2
	${DIFF} -ur ${WRKDIR}/regression-test1 ${WRKDIR}/regression-test2 > /dev/null

.include <bsd.port.mk>
