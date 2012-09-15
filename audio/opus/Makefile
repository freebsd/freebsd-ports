# $FreeBSD$

PORTNAME=	opus
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/ \
		https://ftp.mozilla.org/pub/mozilla.org/opus/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive speech and audio codec

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc   # requires doxygen
MAKE_JOBS_SAFE=	yes

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
