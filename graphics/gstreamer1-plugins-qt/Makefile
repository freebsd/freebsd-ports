PORTREVISION=	0
CATEGORIES=	graphics

COMMENT=	GStreamer Qt videosink plugin

GST_PLUGIN_SUFFIX=	-qt
GST_PLUGIN=	qt5
DIST=		good

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USES=		compiler:c++11-lang qt:5
USE_QT=		core gui declarative buildtools:build linguisttools network \
		x11extras
USE_GSTREAMER=	gl

.include "${MASTERDIR}/Makefile"
