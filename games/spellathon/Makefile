# Created by: Girish <girish.rao.dev@gmail.com>
# $FreeBSD$

PORTNAME=	spellathon
PORTVERSION=	6.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Spellathon%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Word game to test your English vocabulary skills

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig

CXXFLAGS+=	-fPIC
USES=		gettext iconv qmake
USE_GNOME=	glib20
USE_QT4=	corelib gui moc_build rcc_build uic_build
USE_XORG=	ice sm x11 xau xcb xdmcp xext xrender
USE_LDCONFIG=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/src/gui

DESKTOP_ENTRIES="Spellathon" "" "" "${PORTNAME}" "Education;Languages;" true

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${CC}|$${CXX}|g ; \
		s|$${CFLAGS}|$${CXXFLAGS}|g ; \
		s|qmake-qt4|${TRUE}|'
	@${REINPLACE_CMD} \
		's|dict/words.txt|${DATADIR}/words.txt|' ${WRKSRC}/src/logic/defines.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellathon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spellathon-cl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libspellathon.so.0.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libspellathon.so.0.0 ${STAGEDIR}${PREFIX}/lib/libspellathon.so
	${LN} -sf libspellathon.so.0.0 ${STAGEDIR}${PREFIX}/lib/libspellathon.so.0
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dict/words.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
