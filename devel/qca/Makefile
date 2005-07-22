# New ports collection makefile for:	qca
# Date created:				27 March 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	qca
PORTVERSION=	1.0
CATEGORIES=	devel security
MASTER_SITES=	http://psi.affinix.com/beta/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Straightforward and cross-platform crypto API

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
USE_INSTALL_SCRIPT=	yes
USE_BZIP2=	yes
USE_QT_VER=	3
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${X11BASE}
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

do-install:
	${TEST} -d ${PREFIX}/include/plugins/qca || ${MKDIR} ${PREFIX}/include/plugins/qca
	${INSTALL_SCRIPT} ${WRKSRC}/src/qca.h ${WRKSRC}/src/qcaprovider.h ${PREFIX}/include/plugins/qca
	${INSTALL_SCRIPT} -m 755 ${WRKSRC}/libqca.so.1.0.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libqca.so.1.0.0 ${PREFIX}/lib/libqca.so.1
	${LN} -sf ${PREFIX}/lib/libqca.so.1.0.0 ${PREFIX}/lib/libqca.so

.include <bsd.port.mk>
