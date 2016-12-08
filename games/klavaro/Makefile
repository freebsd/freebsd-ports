# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	klavaro
PORTVERSION=	3.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Touchtyping trainer

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		pkgconfig gettext gmake iconv tar:bzip2
USE_GNOME=	gtk30 intlhack
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-rdynamic
LIBS+=		-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' \
		${WRKSRC}/data/klavaro.desktop.in

pre-build:
	@${REINPLACE_CMD} -e 's|^am__append_1|#am__append_1|' \
		${WRKSRC}/src/Makefile

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
