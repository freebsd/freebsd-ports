# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	qhacc
PORTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Qt-based financial manager

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libqwt6.so:${PORTSDIR}/x11-toolkits/qwt6

OPTIONS_DEFINE=	DOCS DEBUG

USES=		qmake
USE_QT4=	corelib gui sql moc_build qmake_build rcc_build uic_build
USE_GCC=	yes
USE_LDCONFIG=	yes

CXXFLAGS+=	-fpermissive

DESKTOP_ENTRIES="QHacc" "Financial manager" "" "${PORTNAME}" "" ""

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
BUILD_TYPE=	debug
.else
BUILD_TYPE=	release
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INSTALLDIR/s|=.*|=${DATADIR}| ; \
		 /^QWTINCS/s|=.*|=${LOCALBASE}/include/qwt6| ; \
		 /^QWTLIBS/s|=.*|=${LOCALBASE}/lib -lqwt6| ; \
		 /^CONFIG +=/s|debug|${BUILD_TYPE}|' ${WRKSRC}/user.pri
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include| ; \
		 s|-lqwt||' ${WRKSRC}/gui/gui.pro
	@${REINPLACE_CMD} -e \
		's|/../qm/|/../share/qhacc/|' ${WRKSRC}/gui/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gui/build/${BUILD_TYPE}/qhacc \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/engine/build/${BUILD_TYPE}/libengine.so.1.0.0 \
		${STAGEDIR}${PREFIX}/lib
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so.1
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so.1.0
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/qm/*.qm ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README THANKS TODO UPGRADE
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
