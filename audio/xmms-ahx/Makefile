# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-ahx
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS plugin for playing AHX tunes

LICENSE=	GPLv2

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libahx.so

GNU_CONFIGURE=	yes
USES=		gmake libtool gettext-runtime
USE_XORG=	xi xext x11
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
