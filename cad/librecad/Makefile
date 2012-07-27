# New ports collection makefile for:	librecad
# Date created:		2012-01-03
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librecad
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	LOCAL/makc

MAINTAINER=	makc@FreeBSD.org
COMMENT=	2D CAD system

USE_XZ=	yes
USE_QT4=	help qt3support help-tools_build moc_build qmake_build \
		rcc_build uic_build uic3_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/src/lib/engine/rs_system.cpp
	${REINPLACE_CMD} -e \
		'/^Icon/s,librecad,${PREFIX}/share/pixmaps/librecad.png,' \
		${WRKSRC}/desktop/librecad.desktop

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS})

post-build:
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/lrelease-qt4 -compress librecad.pro)
	${MKDIR} ${WRKSRC}/unix/resources/qm
	${INSTALL_DATA} ${WRKSRC}/ts/*.qm ${WRKSRC}/unix/resources/qm
.endif
	cd ${WRKSRC} && ${SH} scripts/postprocess-unix.sh

do-install:
	${MKDIR} ${PREFIX}/bin && \
	${INSTALL_PROGRAM} ${WRKSRC}/unix/librecad ${PREFIX}/bin
	cd ${WRKSRC}/unix/resources && ${COPYTREE_SHARE} . ${DATADIR}
	${MKDIR} ${PREFIX}/share/applications && \
	${INSTALL_DATA} ${WRKSRC}/desktop/librecad.desktop \
		${PREFIX}/share/applications
	${MKDIR} ${PREFIX}/share/pixmaps && \
	${INSTALL_DATA} ${WRKSRC}/res/main/librecad.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
