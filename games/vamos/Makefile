# Created by: ijliao
# $FreeBSD$

PORTNAME=	vamos
PORTVERSION=	0.7.1
PORTREVISION=	21
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automotive simulation framework

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gl libtool openal:al,alut pkgconfig sdl xorg
USE_CXXSTD=	c++98
USE_XORG=	sm ice x11 xi xext xmu
USE_GL=		glut
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_freeglut_glutGetModifiers=no \
		--disable-unit-tests
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

INFO=		vamos
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Vamos" "" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" ""

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
.for l in geometry media body track world
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvamos-${l}.so.0
.endfor

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog README TODO doc/matrixfaq.htm" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
