PORTNAME=	minizip
DISTVERSION=	1.3.1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/madler/zlib/releases/download/v${DISTVERSION}/
DISTNAME=	zlib-${DISTVERSION}

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Zip library and programs from Zlib distribution
WWW=		https://www.winimage.com/zLibDll/minizip.html

LICENSE=	ZLIB

USES=		autoreconf cpe libtool tar:xz
CPE_VENDOR=	minizip_project
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-demos
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/zlib-${DISTVERSION}/contrib/minizip

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-test:
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
