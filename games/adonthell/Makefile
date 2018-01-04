# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$
#    $MCom: ports/games/adonthell/Makefile,v 1.1 2006/10/04 20:13:33 ahze Exp $

PORTNAME=	adonthell
PORTVERSION=	0.3.5
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	SAVANNAH
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX} \
		wastesedge-src-${WEDGE_VERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free role playing game

LICENSE=	GPLv2
LICENSE_DISTFILES=	${DISTFILES}

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USES=		gettext gmake python:2.7
USE_SDL=	mixer ttf sdl
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYPACKAGE="${PYTHON_CMD}" ac_cv_path_P_SWIG=no
CONFIGURE_ARGS=	--disable-py-debug

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/adonthell \
		bin/adonthell-${PORTVERSION:R} \
		bin/adonthell-wastesedge \
		share/pixmaps/wastesedge_16x16.xpm \
		share/pixmaps/wastesedge_32x32.xpm
PORTDATA=	*

BROKEN_sparc64=	Does not build on sparc64

DESKTOP_ENTRIES="Adonthell" "" "" "adonthell" "" ""

WEDGE_VERSION=	0.3.5

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e \
		's|-g -Wall|$$CFLAGS -Wall|g ; \
		 s|-lpthread|-pthread|g' configure
	@cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${REINPLACE_CMD} -e \
		's|@adonthell_binary@|${PREFIX}/bin/adonthell|' Makefile.in
	@cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${REINPLACE_CMD} -e \
		's|test $$adonthell_major_ver -eq 0 .*|true ;|' configure
	@cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${REINPLACE_CMD} -e \
		's|^[[:space:]]*_||' scripts/modules/player_text.py

post-install:
	cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} \
		&& ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} \
			--with-adonthell-binary=${STAGEDIR}${PREFIX}/bin/adonthell \
			${CONFIGURE_TARGET}
	cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${SETENV} HOME=${WRKDIR} \
		${MAKE_CMD}
	cd ${WRKDIR}/wastesedge-${WEDGE_VERSION} && ${SETENV} HOME=${WRKDIR} \
		${MAKE_CMD} ${MAKE_ARGS} ${INSTALL_TARGET}

.include <bsd.port.mk>
