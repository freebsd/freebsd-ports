PORTNAME=	libestr
PORTVERSION=	0.1.11
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://libestr.adiscon.com/files/download/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Library for some string essentials

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix
CPE_VENDOR=	adiscon
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-testbench

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
