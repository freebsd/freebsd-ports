# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-jam
COMMENT=	Build tool from the boost.org

PLIST_FILES=	bin/bjam

EXTRACT_AFTER_ARGS=	${DISTNAME}/${WRKSRC_SUBDIR}
MAKE_CMD=	./build.sh
ALL_TARGET=	cc
MAKE_FLAGS=	#
_MAKE_JOBS=	#
MAKEFILE=	#

WRKSRC_SUBDIR=	tools/build/src/engine

.include "${.CURDIR}/../boost-all/common.mk"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin.*/bjam \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
