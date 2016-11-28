# $FreeBSD$

PORTNAME=	libmodbus
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://libmodbus.org/site_media/build/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Modbus library

LICENSE=	LGPL21+
LICENES_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		xmlto:textproc/xmlto

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
