# New ports collection makefile for:	opus
# Date created:        2012-07-19
# Whom:                Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opus
PORTVERSION=	0.9.14
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

# Don't install dummy doxygen-build.stamp
MAKE_ARGS+=	docdir="" doc_DATA=""

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
