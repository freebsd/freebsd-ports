# New ports collection makefile for:	qextmdi
# Date created:				29 April 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$

PORTNAME=	qextmdi
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/gigafalk/qextmdi/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt extension for creating SDI/MDI user interfaces

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

.if defined(WITH_KDE)
USE_KDELIBS_VER=	3
PKGNAMESUFFIX=	-kde
.else
USE_QT_VER=	3
.endif
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/qextmdi
MAKE_ENV+=	QTDIR=${QT_PREFIX} QMAKESPEC=${PREFIX}/share/qt/mkspecs/freebsd-g++ KDE2DIR=${LOCALBASE}
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_KDE)
LIBNAME=	kextmdi
.else
LIBNAME=	qextmdi
.endif
PLIST_SUB+=	LIBNAME=${LIBNAME}

pre-configure:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|tmake|qmake|g' configure
	@cd ${WRKSRC}/qextmdi && ${REINPLACE_CMD} -e 's|warn_on|warn_on thread|g' *.pro
.if !defined(WITH_KDE)
	@${ECHO_CMD}
	@${ECHO_CMD} "Note: The QextMDI library can be build with KDE support."
	@${ECHO_CMD} "      Please specify WITH_KDE in case you want to do so."
	@${ECHO_CMD}
.endif

do-configure:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} qmake ${LIBNAME}.pro

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/lib${LIBNAME}.so.2.0.2 ${PREFIX}/lib/lib${LIBNAME}.so.2
	${LN} ${PREFIX}/lib/lib${LIBNAME}.so.2 ${PREFIX}/lib/lib${LIBNAME}.so
	${MKDIR} ${PREFIX}/include/qextmdi
	${INSTALL_DATA} ${WRKSRC}/include/*.h  ${PREFIX}/include/qextmdi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/qextmdi
	@cd ${WRKSRC}/doc && ${TAR} cf - * | (cd ${PREFIX}/share/doc/qextmdi && ${TAR} xf -)
.endif

.include <bsd.port.post.mk>
