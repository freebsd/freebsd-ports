# Created by: Girish <girish.rao.dev@gmail.com>
# $FreeBSD$

PORTNAME=	spellathon
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Spellathon%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Word game to test your English vocabulary skills

LICENSE=	BSD

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb

CXXFLAGS+=	-fPIC
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GNOME=	glib20
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
USE_XORG=	ice sm x11 xau xdmcp xext xrender
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Spellathon" "${COMMENT}" "" "${PORTNAME}" "Education;Languages;" "true"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${CC}|$${CXX}|g ; \
		 s|$${CFLAGS}|$${CXXFLAGS}|g ; \
		 s|qmake-qt4|${TRUE}|'
	@${REINPLACE_CMD} \
		's|dict/words.txt|${DATADIR}/words.txt|' ${WRKSRC}/src/logic/defines.h

do-configure:
	@(cd ${WRKSRC}/src/gui && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellathon ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spellathon-cl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libspellathon.so.0.0 ${PREFIX}/lib
	${LN} -sf libspellathon.so.0.0 ${PREFIX}/lib/libspellathon.so
	${LN} -sf libspellathon.so.0.0 ${PREFIX}/lib/libspellathon.so.0
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dict/words.txt ${DATADIR}

.include <bsd.port.mk>
