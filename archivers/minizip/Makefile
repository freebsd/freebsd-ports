# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	minizip
PORTVERSION=	1.2.8
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/madler/zlib/archive/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Minizip and miniunz programs from Zlib contributions

LICENSE=	ZLIB

WRKSRC=		${WRKDIR}/zlib-${PORTVERSION}/contrib/minizip
MAKE_ARGS=	CFLAGS="${CPPFLAGS} ${CFLAGS} -include sys/stat.h -include stdint.h"

USE_ZIP=	yes

.include <bsd.port.pre.mk>

# work around missing typedef in 8.X's libz configuration
.if ${OSVERSION} < 900000
CPPFLAGS+=	-Dz_crc_t=uint32_t
.endif

post-patch:
	${REINPLACE_CMD} -e 's/#ifdef unix \|\| __APPLE__/#ifdef unix/' ${WRKSRC}/mini???.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${WRKSRC}/miniunz ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1

regression-test:
	${RM} -f ${WRKDIR}/test.zip && (cd ${WRKSRC} && ./${PORTNAME} ${WRKDIR}/test.zip *)
	${RM} -rf ${WRKDIR}/regression-test && ${MKDIR} ${WRKDIR}/regression-test
	${WRKSRC}/miniunz ${WRKDIR}/test.zip -d ${WRKDIR}/regression-test
	diff -ur >/dev/null ${WRKSRC} ${WRKDIR}/regression-test

.include <bsd.port.post.mk>
