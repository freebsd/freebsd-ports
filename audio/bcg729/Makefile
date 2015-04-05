# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/linphone/plugins/sources

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MEDIASTREAMER
OPTIONS_DEFAULT=	MEDIASTREAMER

MEDIASTREAMER_DESC=	Mediastreamer(linphone) support

OPTIONS_SUB=	yes
MEDIASTREAMER_CONFIGURE_ENABLE=	msplugin
MEDIASTREAMER_LIB_DEPENDS=	libortp.so:${PORTSDIR}/net/ortp \
				libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer

.include <bsd.port.mk>
