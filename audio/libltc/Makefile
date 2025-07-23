PORTNAME=	libltc
DISTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/x42/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Linear/Logitudinal Time Code (LTC) Library
WWW=		https://github.com/x42/libltc

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFIGURE_ENV=	ac_cv_path_DOXYGEN=no
CONFIGURE_ARGS=	--disable-static

.include <bsd.port.mk>
