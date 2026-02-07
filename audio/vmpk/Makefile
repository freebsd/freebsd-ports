PORTNAME=	vmpk
DISTVERSION=	0.9.0
CATEGORIES=	audio
MASTER_SITES=	SF/vmpk/vmpk/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Virtual MIDI Piano Keyboard
WWW=		http://vmpk.sourceforge.net

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdrumstick-rt.so:audio/drumstick

USES=		compiler:c++11-lang cmake gl localbase:ldflags pkgconfig qt:6 tar:bz2 xorg
USE_QT=		base tools:build
USE_GL=		gl opengl
USE_XORG=	xcb

CMAKE_ON=	EMBED_TRANSLATIONS
CMAKE_ARGS=	-DUSE_QT=6

OPTIONS_DEFINE=		DBUS MANPAGES
OPTIONS_DEFAULT=	DBUS MANPAGES
OPTIONS_SUB=		yes

DBUS_CMAKE_BOOL=	ENABLE_DBUS

MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>0:textproc/docbook-xsl

.include <bsd.port.mk>
