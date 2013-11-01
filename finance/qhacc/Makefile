# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	qhacc
PORTVERSION=	4.2
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Qt-based financial manager

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libqwt6.so:${PORTSDIR}/x11-toolkits/qwt6

OPTIONS_DEFINE=	DOCS

USES=		qmake:norecursive
USE_QT4=	corelib gui sql moc_build qmake_build rcc_build uic_build
QMAKE_ARGS=	${QMAKEFLAGS}
USE_GCC=	yes
USE_LDCONFIG=	yes

CXXFLAGS+=	-fpermissive

DESKTOP_ENTRIES="QHacc" "" "" "${PORTNAME}" "" ""

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INSTALLDIR/s|=.*|=${DATADIR}| ; \
		 /^QWTINCS/s|=.*|=${LOCALBASE}/include/qwt6| ; \
		 /^QWTLIBS/s|=.*|=${LOCALBASE}/lib -lqwt6| ; \
		 /+= debug/s|^|#|' ${WRKSRC}/user.pri
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include| ; \
		 s|-lqwt||' ${WRKSRC}/gui/gui.pro
	@${REINPLACE_CMD} -e \
		's|/../qm/|/../share/qhacc/|' ${WRKSRC}/gui/main.cpp

do-install:
	(cd ${WRKSRC}/gui/build/release && ${INSTALL_PROGRAM} \
		qhacc ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/engine/build/release && ${INSTALL_DATA} \
		libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib)
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so.1
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so.1.0
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/qm && ${INSTALL_DATA} *.qm ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README THANKS TODO UPGRADE
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
