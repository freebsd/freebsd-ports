# New ports collection makefile for:	Stellarium
# Date created:				26 Jan 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	stellarium
PORTVERSION=	0.10.5
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/Stellarium-sources/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A 3D photo-realistic sky renderer

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_CMAKE=	yes
CMAKE_ARGS+=	-DFreeType2_INCLUDE_DIR="${LOCALBASE}/include/freetype2" \
		-DCMAKE_EXE_LINKER_FLAGS="-L${LOCALBASE}/lib"
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build rcc_build uic_build qmake_build \
		corelib gui opengl script network svg qtestlib sql

MAN1=		stellarium.1
PORTDOCS=	AUTHORS ChangeLog README

DESKTOP_ENTRIES="Stellarium" \
		"View the sky" \
		"${DATADIR}/data/stellarium.ico" \
		"stellarium" \
		"Application;Astronomy;Education;Science;" \
		false

post-patch:
# `_assert' conflicts with some macros on FreeBSD 6.x
	@${REINPLACE_CMD} -e 's|_assert|_&_|' ${WRKSRC}/src/tests/*.cpp
	@${REINPLACE_CMD} -e '/typedef.*void.*__GLXextFuncPtr/ d' \
		${WRKSRC}/src/core/external/GLee.h
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		${WRKSRC}/doc/CMakeLists.txt
# avoid picking up the wrong `fixx11h.h' (x11/kdelibs3 port installs one that
# doesn't handle FontChange)
	@${FIND} ${WRKSRC}/src ${WRKSRC}/plugins -type f -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/fixx11h\.h/fixx11qt4h.h/'
	@cd ${WRKSRC}/src/core/external && ${MV} fixx11h.h fixx11qt4h.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
