# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	luxrender
PORTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://src.luxrender.net/lux/archive/ \
		http://freebsd.nsu.ru/distfiles/luxrender/
DISTNAME=	${HG_NODEID}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Physically based and unbiased rendering system

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	i386 amd64
BROKEN=		does not build with boost-1.48.0

BUILD_DEPENDS=	${LOCALBASE}/lib/libfreeimage.a:${PORTSDIR}/graphics/freeimage
LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		png15:${PORTSDIR}/graphics/png \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \

HG_NODEID=	9206b3ba7011

USE_BZIP2=	yes
USES=		bison cmake
WRKSRC=		${WRKDIR}/lux-${HG_NODEID}

DESKTOP_ENTRIES="LuxRender" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/luxrender.svg" "${PORTNAME}" \
		"Graphics;3DGraphics;" false

OPTIONS_DEFINE=		QT4 WX
OPTIONS_DEFAULT=	QT4

QT4_DESC=		Qt4-enabled GUI executable
WX_DESC=		wxWidgets-enabled GUI executable

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	moc_build qmake_build rcc_build uic_build corelib gui
PLIST_FILES+=	bin/luxrender
.endif

.if ${PORT_OPTIONS:MWX}
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

.include <bsd.port.mk>
