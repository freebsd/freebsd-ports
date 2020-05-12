# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	graphics

COMMENT=	GStreamer OpenExr codec plugin

USES+=		compiler:c++11-lang
GST_PLUGIN=	openexr
DIST=		bad

pre-configure:
		${REINPLACE_CMD} -e 's/c++98/c++11/' ${WRKSRC}/ext/openexr/Makefile.in

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

.include "${MASTERDIR}/Makefile"
