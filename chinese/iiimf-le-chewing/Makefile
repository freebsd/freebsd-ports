# New ports collection makefile for:	iiimf-le-chewing
# Date created:		8 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	iiimf-le-chewing
PORTVERSION=	0.01
CATEGORIES=	chinese textproc
MASTER_SITES=	http://wagner.elixus.org/~clkao/
DISTFILES=	iiimf-chewing.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF Chewing engine, an intelligent Chinese phonetic input method

LIB_DEPENDS=	chewing.2:${PORTSDIR}/chinese/libchewing
BUILD_DEPENDS=	${LOCALBASE}/include/iiimf/iml/SunIM.h:${PORTSDIR}/textproc/iiimf-headers
RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

WRKSRC=		${WRKDIR}/trunk
USE_ICONV=	yes

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o chewing.so -shared -fPIC -DARCH=\"${MACHINE_ARCH}\" \
	-I${LOCALBASE}/include -I${LOCALBASE}/include/iiimf -I${LOCALBASE}/include/iiimf/iml -I${LOCALBASE}/include/chewing \
	chewing.c -L${LOCALBASE}/lib -lchewing -liconv

do-install:
	${MKDIR} ${PREFIX}/lib/im/leif
	${INSTALL_DATA} ${WRKSRC}/chewing.so ${PREFIX}/lib/im/leif

.include <bsd.port.mk>
