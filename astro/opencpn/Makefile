# $FreeBSD$

PORTNAME=	opencpn
PORTVERSION=	5.0.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	astro geography

MAINTAINER=	ml@netfence.it
COMMENT=	Concise ChartPlotter/Navigator

LICENSE=	GPLv2+

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libtinyxml.so:textproc/tinyxml \
		liblz4.so:archivers/liblz4

USES=		cmake compiler:c++11-lang gettext-tools gl gnome \
		localbase pkgconfig sqlite xorg
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	OpenCPN
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk30 pango
INSTALLS_ICONS=	yes
USE_LDCONFIG=	${PREFIX}/lib/opencpn
USE_WX=		3.0+
USE_XORG=	ice sm x11 xext

CMAKE_ARGS=	-DBUNDLE_GSHHS=CRUDE
CMAKE_ON=	BUNDLE_TCDATA OCPN_FORCE_GTK3
CMAKE_OFF=	OCPN_NEW_SERIAL

OPTIONS_DEFINE=	DOCS
DOCS_CMAKE_ON=	-DBUNDLE_DOCS:STRING="ON"
DOCS_CMAKE_OFF=	-DBUNDLE_DOCS:STRING="OFF"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/mygdal/cpl_csv.cpp \
		${WRKSRC}/src/mygdal/cpl_findfile.cpp \
		${WRKSRC}/data/doc/help_en_US.html
.if ${ARCH} != amd64 && ${ARCH} != i386
	@${REINPLACE_CMD} -e '/-msse/d' -e '/-mssse3/d' \
		-e '/-mavx2/d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
