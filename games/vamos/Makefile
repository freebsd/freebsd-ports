# Created by: ijliao
# $FreeBSD$

PORTNAME=	vamos
PORTVERSION=	0.7.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Automotive simulation framework

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libpng15.so:${PORTSDIR}/graphics/png

USES=		openal:al,alut pkgconfig
USE_XORG=	sm ice x11 xi xext xmu
USE_GL=		glut
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	ac_cv_lib_freeglut_glutGetModifiers=no \
		--disable-unit-tests
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

INFO=		vamos

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog README TODO

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	matrixfaq.htm

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Vamos" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/config/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^AM_CXXFLAGS/s| -pedantic|| ; \
		 /^AM_CXXFLAGS/s| -O[[:alnum:]]|| ; \
		 /^AM_CXXFLAGS/s| -g|| ; \
		 /^AM_CXXFLAGS/s| -DBOOST_TEST_DYN_LINK|| ; \
		 /^AM_CXXFLAGS/s| -L/usr/lib/boost||'

post-install:
.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
