# Created by: ijliao
# $FreeBSD$

PORTNAME=	vamos
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Automotive simulation framework

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_OPENAL=	al alut
USE_XORG=	sm ice x11 xi xext xmu
USE_GL=		glut
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	ac_cv_header_boost_test_unit_test_hpp=no \
		ac_cv_lib_freeglut_glutGetModifiers=no
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

# Wrong versioning upstream
PORTSCOUT=	skipv:0.7.1

INFO=		vamos

PORTDOCS=	AUTHORS ChangeLog README TODO

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Vamos" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

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
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
