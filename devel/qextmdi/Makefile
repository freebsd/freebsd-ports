# New ports collection makefile for:	qextmdi
# Date created:				29 April 2002
# Whom:					jesse@cs.uni-magdeburg.de
#
# $FreeBSD$

PORTNAME=	qextmdi
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.geocities.com/gigafalk/qextmdi/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	KDE

MAINTAINER=	jesse@cs.uni-magdeburg.de

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/qextmdi
USE_QT_VER=	3
USE_X_PREFIX=	yes
.if defined(WITH_KDE)
USE_KDEBASE_VER=	3
# The name of this option is misleading. It uses either KDE2 or KDE3.
CONFIGURE_ARGS+=	-kde2
.endif
MAKE_ENV+=	QTDIR=${QT_PREFIX} QMAKESPEC=freebsd-g++
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

pre-configure:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|tmake|qmake|g' configure
	@cd ${WRKSRC}/qextmdi && ${PERL} -e 's|warn_on|warn_on thread|g' *.pro

# define this here to prevent any "--with-qt-includes" or similar:
do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIG_ARGS}

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libqextmdi.so.2.0.2 ${PREFIX}/lib/libqextmdi.so.2
	${LN} ${PREFIX}/lib/libqextmdi.so.2 ${PREFIX}/lib/libqextmdi.so
	${INSTALL_DATA} ${WRKSRC}/include/*.h  ${PREFIX}/include
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/qextmdi
	@cd ${WRKSRC}/doc && ${TAR} cf - * | (cd ${PREFIX}/share/doc/qextmdi && ${TAR} xf -)
.endif

.include <bsd.port.mk>
