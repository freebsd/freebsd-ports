PORTNAME=	libmodbus
PORTVERSION=	3.1.7
CATEGORIES=	comms
MASTER_SITES=	https://libmodbus.org/releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modbus library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		xmlto:textproc/xmlto

USES=		cpe gmake libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
