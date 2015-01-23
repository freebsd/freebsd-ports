# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/linphone/plugins/sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmediastreamer_base.so:${PORTSDIR}/net/mediastreamer \
		libortp.so:${PORTSDIR}/net/ortp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-strict
INSTALL_TARGET=	install-strip
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
