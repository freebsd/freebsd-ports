# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	nekobee
PORTVERSION=	0.1.8
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSSI plugin that emulates the sound of the TB-303 Bassline

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:audio/dssi
LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libjack.so:audio/jack

USE_GITHUB=	yes
GH_ACCOUNT=	gordonjcp

USES=		gnome pkgconfig waf
USE_GNOME=	gtk20

CPPFLAGS+=	-I${LOCALBASE}/include/dssi -I${LOCALBASE}/include
LDFLAGS+=	-lm

post-patch:
	@${REINPLACE_CMD} -e \
		'/LINKFLAGS/s|^|#|' ${WRKSRC}/wscript

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/nekobee.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/nekobee/nekobee_gtk

.include <bsd.port.mk>
