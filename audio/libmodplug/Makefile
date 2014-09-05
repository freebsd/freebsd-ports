# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	libmodplug
PORTVERSION=	0.8.8.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/modplug-xmms/${PORTNAME}/${PORTVERSION} CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	ModPlug mod-like music shared libraries

USES=		gmake pathfix pkgconfig libtool:keepla
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS=/d' \
		${WRKSRC}/configure

.include <bsd.port.mk>
