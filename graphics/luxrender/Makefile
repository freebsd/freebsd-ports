# New ports collection makefile for:	LuxRender
# Date created:				16 March 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	luxrender
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://src.luxrender.net/lux/archive/ \
		http://freebsd.nsu.ru/distfiles/luxrender/
DISTNAME=	${HG_NODEID}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Physically based and unbiased rendering system

LICENSE=	GPLv3

BROKEN=		does not build with boost-1.48.0

BUILD_DEPENDS=	${LOCALBASE}/lib/libfreeimage.a:${PORTSDIR}/graphics/freeimage
LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		png15:${PORTSDIR}/graphics/png \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \

HG_NODEID=	9206b3ba7011

USE_BZIP2=	yes
USE_BISON=	build
USE_CMAKE=	yes
CMAKE_VERBOSE=	yes
WRKSRC=		${WRKDIR}/lux-${HG_NODEID}
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="LuxRender" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/luxrender.svg" "${PORTNAME}" \
		"Graphics;3DGraphics;" false

OPTIONS=	QT4	"Build Qt4 GUI executable"		on \
		WX	"Build wxWidgets GUI executable"	off

.include <bsd.port.options.mk>

.if defined(WITH_QT4)
USE_QT4=	moc_build qmake_build rcc_build uic_build corelib gui
PLIST_FILES+=	bin/luxrender
.endif

.if defined(WITH_WX)
USE_WX=		2.8+
PLIST_FILES+=	bin/luxrenderwx
.endif

post-patch:
# Prevent appending `64' suffix to `lib' directory on amd64, do not install
# vendor .desktop file, disable build of Python extension for now
	@${REINPLACE_CMD} -e '/LIB_SUFFIX 64/d ; /luxrender\.desktop/d ; \
		89,95d ; 803,837d' ${WRKSRC}/CMakeLists.txt
# Adjust for libpng 1.4 new API
	@${REINPLACE_CMD} -e \
		's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		-e 's|int_p_NULL|NULL|g' ${WRKSRC}/core/external/cimg.h

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile4: uses i386-specific options
.endif

.include <bsd.port.post.mk>
