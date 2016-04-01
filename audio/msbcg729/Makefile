# $FreeBSD$

PORTNAME=	msbcg729
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/linphone/plugins/sources
DISTNAME=	bcg729-${DISTVERSION}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Software G729A codec plugin for Mediastreamer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libortp.so:net/ortp \
		libmediastreamer_base.so:net/mediastreamer

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-strict
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig

.include <bsd.port.mk>
