PORTNAME=	sfsexp
DISTVERSION=	1.4.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mjsottile/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Small Fast S-Expression Library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
