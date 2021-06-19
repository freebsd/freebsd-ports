# Created by: David Yeske <dyeske@gmail.com>

PORTNAME=	electricsheep
DISTVERSION=	3.0.2.20191005 # configure.ac though says that the version is 2.7b33
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Infinite evolving crowdsourced artwork

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	flam3-animate:graphics/flam3
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libavcodec.so:multimedia/ffmpeg \
		libGLee.so:graphics/glee \
		libgtop-2.0.so:devel/libgtop \
		libpng.so:graphics/png \
		libtinyxml.so:textproc/tinyxml
RUN_DEPENDS=	flam3-animate:graphics/flam3

USES=		autoreconf compiler:c++11-lang dos2unix gl gnome libtool \
		localbase:ldflags lua:51 pkgconfig gettext-runtime xorg
USE_GITHUB=	yes
GH_ACCOUNT=	scottdraves
GH_TAGNAME=	37ba0fd692d6581f8fe009ed11c9650cd8174123
DOS2UNIX_FILES=	ContentDownloader/SheepDownloader.cpp DisplayOutput/OpenGL/glx.cpp
GNU_CONFIGURE=	yes
USE_WX=		3.1
USE_GNOME=	glib20
USE_GL=		gl glut
USE_XORG=	x11 xrender

WRKSRC_SUBDIR=	client_generic

CFLAGS+=	-DLINUX_GNU -I${LOCALBASE}/include/GL -I${LOCALBASE}/include/libavcodec -DSHAREDIR='\"${DATADIR}\"'

post-patch: # unbundle GLee
	@${RM} ${WRKSRC}/DisplayOutput/OpenGL/GLee.*

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}* ${STAGEDIR}${DATADIR}/icons

.include <bsd.port.mk>
