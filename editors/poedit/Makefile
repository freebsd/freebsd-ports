PORTNAME=	poedit
DISTVERSION=	3.4.2
PORTREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	https://github.com/vslavik/${PORTNAME}/releases/download/v${DISTVERSION}-oss/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Gettext catalogs (.po files) editor
WWW=		https://www.poedit.net/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libenchant-2.so:textproc/enchant2 \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libharfbuzz.so:print/harfbuzz \
		libicui18n.so:devel/icu \
		liblucene++.so:textproc/luceneplusplus

USES=				autoreconf desktop-file-utils gettext-tools:build,run \
				gmake gnome pkgconfig
USE_GNOME=			cairo gdkpixbuf glib20 gtk30 pango
USE_WX=				3.2
WX_CONF_ARGS=			absolute
GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -e '/AX_BOOST_SYSTEM/d' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
