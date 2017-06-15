# $FreeBSD$

PORTREVISION=	1
CATEGORIES=	graphics

COMMENT=	GStreamer opencv real time computer vision plugin

GST_PLUGIN=	opencv
DIST=		bad

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

# Clang has issues with Overloaded stuff inside OpenCV
CXXFLAGS+=	-Wno-overloaded-virtual

.include "${MASTERDIR}/Makefile"
