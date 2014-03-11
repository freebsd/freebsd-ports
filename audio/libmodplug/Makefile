# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	libmodplug
PORTVERSION=	0.8.8.5
CATEGORIES=	audio
MASTER_SITES=	SF/modplug-xmms/${PORTNAME}/${PORTVERSION} CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	ModPlug mod-like music shared libraries

USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS=/d' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmodplug.so.1

.include <bsd.port.mk>
