# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xymms
DISTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Sega Genesis GYM plugin for XMMS

LIB_DEPENDS=	libxmms.so:multimedia/xmms

GNU_CONFIGURE=	yes
USES=		libtool
USE_GNOME=	gtk12
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-static

PLIST_FILES=	lib/xmms/Input/libxymms.so \
		%%EXAMPLESDIR%%/sample.gym

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/sample.gym ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
