# Created by: John Hixson <jhixson@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pianod2
PORTVERSION=	306
CATEGORIES=	audio
MASTER_SITES=	http://deviousfish.com/Downloads/pianod2/Devel/

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Free, multi-source, network-controlled music player daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	fails to build

LIB_DEPENDS=	libao.so:audio/libao \
	libavcodec.so:multimedia/ffmpeg \
	libgcrypt.so:security/libgcrypt \
	libgstreamer-1.0.so:multimedia/gstreamer1 \
	libgzstream.so:devel/gzstream \
	libcurl.so:ftp/curl \
	libgnutls.so:security/gnutls \
	libjson-c.so:devel/json-c \
	libSDL.so:devel/sdl12 \
	libtag.so:audio/taglib
RUN_DEPENDS=	mksh>0:shells/mksh

USES=	autoreconf compiler:c11 gettext gmake gnome pkgconfig shebangfix

USE_GNOME=	glib20
USE_GSTREAMER=	ffmpeg

USE_RC_SUBR=	pianod

GNU_CONFIGURE=	yes

SHEBANG_FILES=	contrib/piano contrib/runmix
ksh_CMD=	${LOCALBASE}/bin/mksh

CONFIGURE_ARGS=	--with-compression \
	--with-accesscontrol \
	--with-engine=gstreamer \
	--with-libao \
	--with-libsdl \
	--with-tonegenerator \
	--with-pandora \
	--with-tls \
	--with-taglib

MAKE_ARGS=	CC="${CC}" PREFIX="${PREFIX}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
