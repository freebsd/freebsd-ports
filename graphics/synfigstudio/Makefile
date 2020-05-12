# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	synfigstudio
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=v
PORTREVISION=	4
CATEGORIES=	graphics multimedia

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Vector-based 2D animation software package

LICENSE=	GPLv2+

BUILD_DEPENDS=	etl>=1.2.2:devel/etl
LIB_DEPENDS=	libHalf.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libMagick++-6.so:graphics/ImageMagick6 \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libmlt.so:multimedia/mlt \
		libsynfig.so:devel/synfig
RUN_DEPENDS=	xdg-open:devel/xdg-utils

PORTSCOUT=	limitw:1,even

USES=		autoreconf compiler:c++11-lang desktop-file-utils \
		gmake gnome libtool localbase pathfix pkgconfig \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	synfig
GH_PROJECT=	synfig
WRKSRC_SUBDIR=	synfig-studio
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-mimedb
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS JACK NLS
OPTIONS_SUB=	yes

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS NEWS README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
