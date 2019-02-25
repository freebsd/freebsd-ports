# $FreeBSD$

PORTNAME=	opencpn
PORTVERSION=	4.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	astro geography

MAINTAINER=	ml@netfence.it
COMMENT=	Concise ChartPlotter/Navigator

LICENSE=	GPLv2+

BROKEN_aarch64=		Fails to compile: use of undeclared identifier rand

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libtinyxml.so:textproc/tinyxml

USE_GITHUB=	yes
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	OpenCPN

USES=		cmake compiler:c++11-lib gettext-tools gl gnome localbase
USE_CXXSTD=	c++11
USE_GL=		gl
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_WX=		3.0+
USE_XORG=	x11
INSTALLS_ICONS=	yes

CMAKE_ARGS=	-DBUNDLE_DOCS=ON -DBUNDLE_GSHHS=CRUDE -DBUNDLE_TCDATA=ON
LDFLAGS+=	-Wl,-E # plugins
LDFLAGS+=	-Wl,--as-needed # ICE, SM, Xext

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/mygdal/cpl_csv.cpp \
		${WRKSRC}/src/mygdal/cpl_findfile.cpp \
		${WRKSRC}/data/doc/help_en_US.html
.if exists(/usr/lib/libstdc++.so)
	@${REINPLACE_CMD} -e '/-msse/d' -e '/-mssse3/d' \
		-e '/-mavx2/d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
