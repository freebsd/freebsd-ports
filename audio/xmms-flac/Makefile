# $FreeBSD$

PORTNAME=	xmms-flac
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/
DISTNAME=	flac-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libogg.so:${PORTSDIR}/audio/libogg

USES=		gettext iconv tar:xz
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk12
USE_XORG=	x11 xau xcb xdmcp xext xi

CONFIGURE_ARGS=	--disable-silent-rules
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ARGS=	LIBTOOL="${LIBTOOL} --tag=disable-static"
MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	lib/xmms/Input/libxmms-flac.so

.include <bsd.port.mk>
