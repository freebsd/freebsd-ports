# New ports collection Makefile for:	esvn
# Date created:        9 August 2004
# Whom:                Andrej Zverev (az@inec.ru)
#
# $FreeBSD$
#

PORTNAME=	esvn
PORTVERSION=	0.4.7
CATEGORIES=	devel
MASTER_SITES=	http://esvn.umputun.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	az@inec.ru
COMMENT=	GUI frontend for the Subversion revision system

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

ESVN_DIST=	esvn

WRKSRC=		${WRKDIR}/${ESVN_DIST}

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${X11BASE}
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PLIST_FILES=	bin/esvn

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ esvn.pro

post-configure:
.if exists(/boot/modules/nvidia.ko) && ${OSVERSION} > 502122
	${REINPLACE_CMD} -e 's#-lpthread#-lc_r#' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esvn ${PREFIX}/bin

.include <bsd.port.post.mk>
