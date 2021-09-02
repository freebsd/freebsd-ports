PORTNAME=	libmodbus
PORTVERSION=	3.1.6
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://libmodbus.org/releases/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Modbus library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		xmlto:textproc/xmlto

USES=		cpe gmake libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
