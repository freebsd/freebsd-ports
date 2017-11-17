# $FreeBSD$

PORTNAME=	jalv-select
DISTVERSIONPREFIX=	V
DISTVERSION=	0.9
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Little app to select lv2 plugs for run with jalv

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	jalv:audio/jalv

USES=		gmake gettext-runtime pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	jalv_select
USE_GNOME=	atk atkmm cairo gdkpixbuf2 glib20 glibmm gtk20 gtkmm24 pango pangomm
USE_XORG=	x11

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|PREFIX = /usr|PREFIX ?= /usr|; \
		s|CXXFLAGS = |CXXFLAGS += |; \
		s|LDFLAGS = |LDFLAGS += |; \
		s|MAN_DIR = $$(SHARE_DIR)/man/man1|MAN_DIR = $$(PREFIX)/man/man1|' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jalv.select

.include <bsd.port.mk>
