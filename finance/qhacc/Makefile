# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	qhacc
PORTVERSION=	4.1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple QT-based financial manager

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	qwt6:${PORTSDIR}/x11-toolkits/qwt6

OPTIONS_DEFINE=	DOCS

BROKEN=		Does not build

USE_QT4=	corelib gui sql moc_build qmake_build rcc_build uic_build
USE_GCC=	4.6+
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

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

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	(cd ${WRKSRC}/gui/build/release && ${INSTALL_PROGRAM} \
		qhacc ${PREFIX}/bin)
	(cd ${WRKSRC}/engine/build/release && ${INSTALL_DATA} \
		libengine.so.1.0.0 ${PREFIX}/lib)
	@${LN} -sf libengine.so.1.0.0 ${PREFIX}/lib/libengine.so
	@${LN} -sf libengine.so.1.0.0 ${PREFIX}/lib/libengine.so.1
	@${LN} -sf libengine.so.1.0.0 ${PREFIX}/lib/libengine.so.1.0
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/qm && ${INSTALL_DATA} *.qm ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog README THANKS TODO UPGRADE
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
