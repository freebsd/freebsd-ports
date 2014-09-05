# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-jam
COMMENT=	Build tool from the boost.org

PLIST_FILES=	bin/bjam

EXTRACT_AFTER_ARGS=	${DISTNAME}/tools/build/v2/engine

.include "${.CURDIR}/../boost-all/common.mk"

do-build:
	cd ${WRKSRC}/tools/build/v2/engine && \
		${MAKE_ENV} ./build.sh cc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/v2/engine/bin.*/bjam \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
