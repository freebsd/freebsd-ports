# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	qhacc
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Qt-based financial manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libqwt6.so:x11-toolkits/qwt6

USES=		compiler:c++11-lib qmake:norecursive tar:tgz
USE_QT4=	corelib gui sql moc_build rcc_build uic_build
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

DESKTOP_ENTRIES="QHacc" "" "" "${PORTNAME}" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^INSTALLDIR/s|=.*|=${DATADIR}| ; \
		 /^QWTINCS/s|=.*|=${LOCALBASE}/include/qwt6| ; \
		 /^QWTLIBS/s|=.*|=${LOCALBASE}/lib -lqwt6| ; \
		 /+= debug/s|^|#| ; \
		 /^QMAKE_CFLAGS/s|=.*|= $$$${GPGMEINCS}| ; \
		 /^QMAKE_CXXFLAGS/s|=.*|= $$$${GPGMEINCS}| ; \
		 /^INCLUDEPATH/s|=.*|=|' ${WRKSRC}/user.pri
	@${REINPLACE_CMD} -e \
		's|/usr/include|${LOCALBASE}/include| ; \
		 s|-lqwt||' ${WRKSRC}/gui/gui.pro
	@${REINPLACE_CMD} -e \
		's|/../qm/|/../share/qhacc/|' ${WRKSRC}/gui/main.cpp
	@${FIND} ${WRKSRC} -name "*.cpp" -or -name "*.h" -or -name "*.ui" | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|qwt/||'

do-install:
	(cd ${WRKSRC}/gui/build/release && ${INSTALL_PROGRAM} \
		qhacc ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/engine/build/release && ${INSTALL_LIB} \
		libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib)
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so.1
	@${LN} -sf libengine.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libengine.so.1.0
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/qm && ${INSTALL_DATA} *.qm ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README THANKS TODO UPGRADE
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
