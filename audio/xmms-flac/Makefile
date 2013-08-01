# $FreeBSD$

PORTNAME=	xmms-flac
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/
DISTNAME=	flac-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LIB_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		FLAC:${PORTSDIR}/audio/flac \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		ogg:${PORTSDIR}/audio/libogg

USES=		gettext iconv
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk12
USE_XORG=	x11 xau xcb xdmcp xext xi
USE_XZ=		yes

CONFIGURE_ARGS=	--disable-silent-rules
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ARGS=	LIBTOOL="${LIBTOOL} --tag=disable-static"
MAKEFILE=	${FILESDIR}/Makefile

# XXX
post-install:
	${RM} ${PREFIX}/lib/xmms/Input/libxmms-flac.la

.include <bsd.port.mk>
