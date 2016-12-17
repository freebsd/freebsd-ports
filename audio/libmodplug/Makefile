# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	libmodplug
PORTVERSION=	0.8.8.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/modplug-xmms/${PORTNAME}/${PORTVERSION} LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	ModPlug mod-like music shared libraries

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake pathfix pkgconfig libtool
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPE_VENDOR=	konstanty_bialkowski

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS=/d' \
		${WRKSRC}/configure

.include <bsd.port.mk>
