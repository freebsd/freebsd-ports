# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	minizip
PORTVERSION=	1.2.10
CATEGORIES=	archivers
MASTER_SITES=	SF/libpng/zlib/${PORTVERSION}
DISTNAME=	zlib-${PORTVERSION}

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Zip library and programs from Zlib distribution

LICENSE=	ZLIB

USES=		autoreconf libtool pathfix tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-demos
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/zlib-${PORTVERSION}/contrib/minizip

post-patch:
	@${REINPLACE_CMD} 's/#ifdef unix || __APPLE__/#ifdef unix/' ${WRKSRC}/mini???.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1

regression-test:
	${RM} -r ${WRKDIR}/regression-test1
	${MKDIR} ${WRKDIR}/regression-test1
	${MV} ${WRKSRC}/*.[cho] ${WRKDIR}/regression-test1
	${RM} ${WRKDIR}/test.zip
	(cd ${WRKDIR}/regression-test1 && ${WRKSRC}/minizip ${WRKDIR}/test.zip *)
	${RM} -r ${WRKDIR}/regression-test2
	${MKDIR} ${WRKDIR}/regression-test2
	${WRKSRC}/miniunzip ${WRKDIR}/test.zip -d ${WRKDIR}/regression-test2
	${DIFF} -ur ${WRKDIR}/regression-test1 ${WRKDIR}/regression-test2 > /dev/null

.include <bsd.port.mk>
