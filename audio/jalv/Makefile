# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	jalv
PORTVERSION=	1.6.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple but fully featured LV2 plugin host for Jack

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libjack.so:audio/jack \
		libsord-0.so:devel/sord \
		libserd-0.so:devel/serd \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang qmake:no_configure,no_env qt:5 waf tar:bz2 pkgconfig
CONFIGURE_ARGS=	--no-qt4
USE_CXXSTD=	c++11
USE_QT=		core gui widgets buildtools_build
USE_GNOME=	atk atkmm cairo cairomm pango pangomm libsigc++20 \
		gdkpixbuf2 glib20 glibmm  gtk20 gtk30 gtkmm24

post-patch:
		@${REINPLACE_CMD} 's|$${MANDIR}|${MAN1PREFIX}/man|' \
			${WRKSRC}/wscript

post-install:
		@${GZIP_CMD} ${STAGEDIR}${MAN1PREFIX}/man/man1/*
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jalv*

.include <bsd.port.mk>
