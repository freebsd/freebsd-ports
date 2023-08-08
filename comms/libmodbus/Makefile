PORTNAME=	libmodbus
PORTVERSION=	3.1.7
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	https://libmodbus.org/releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Modbus library
WWW=		https://libmodbus.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		cpe gmake libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=	a2x:textproc/asciidoc \
			xmlto:textproc/xmlto

.include <bsd.port.mk>
