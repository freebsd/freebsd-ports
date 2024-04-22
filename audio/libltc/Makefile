PORTNAME=	libltc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Linear/Logitudinal Time Code (LTC) Library
WWW=		https://github.com/x42/libltc

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	x42

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
