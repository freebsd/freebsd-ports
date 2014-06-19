# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	nhocr
PORTVERSION=	0.21
CATEGORIES=	japanese graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	OCR engine for Japanese language

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/libsip.a:${PORTSDIR}/graphics/O2-tools
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-O2tools=${LOCALBASE} --datadir=${DATADIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ocropus/scripts
	${INSTALL_DATA} ${WRKSRC}/ocropus/rec-nhocr-0.3.lua ${STAGEDIR}${PREFIX}/share/ocropus/scripts/rec-nhocr.lua
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
