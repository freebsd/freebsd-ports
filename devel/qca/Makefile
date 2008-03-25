# New ports collection makefile for:	qca
# Date created:				27 March 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	qca
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://delta.affinix.com/download/qca/ \
		http://mirror.inerd.com/FreeBSD/distfiles/qca/

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	Straightforward and cross-platform crypto API

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_QT_VER=	3
USE_LDCONFIG=	yes

CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${QT_PREFIX}
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

do-install:
	${TEST} -d ${PREFIX}/include/plugins/qca || ${MKDIR} ${PREFIX}/include/plugins/qca
	${INSTALL_SCRIPT} ${WRKSRC}/src/qca.h ${WRKSRC}/src/qcaprovider.h ${PREFIX}/include/plugins/qca
	${INSTALL_SCRIPT} -m 755 ${WRKSRC}/libqca.so.1.0.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libqca.so.1.0.0 ${PREFIX}/lib/libqca.so.1
	${LN} -sf ${PREFIX}/lib/libqca.so.1.0.0 ${PREFIX}/lib/libqca.so

.include <bsd.port.mk>
