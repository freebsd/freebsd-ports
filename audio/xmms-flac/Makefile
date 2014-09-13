# $FreeBSD$

PORTNAME=	xmms-flac
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/
DISTNAME=	flac-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libogg.so:${PORTSDIR}/audio/libogg

USES=		iconv libtool tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	lib/xmms/Input/libxmms-flac.so

.include <bsd.port.mk>
