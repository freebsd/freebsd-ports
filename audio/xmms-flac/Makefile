# $FreeBSD$

PORTNAME=	xmms-flac
PORTVERSION=	1.3.2
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/flac/
DISTNAME=	flac-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS=	libxmms.so:multimedia/xmms \
		libFLAC.so:audio/flac \
		libogg.so:audio/libogg

USES=		gettext-runtime iconv libtool tar:xz
USE_GNOME=	gtk12
USE_XORG=	xi xext x11
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

MAKEFILE=	${FILESDIR}/Makefile

PLIST_FILES=	lib/xmms/Input/libxmms-flac.so

.include <bsd.port.mk>
