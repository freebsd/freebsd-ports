# New ports collection makefile for:   kxl
# Date created:        16 June 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kxl
PORTVERSION=	1.1.5
CATEGORIES=	games
MASTER_SITES=	http://www2.mwnet.or.jp/~fc3srx7/download/
DISTNAME=	KXL-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
INSTALL_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS=="-L${X11BASE}/lib"

.include <bsd.port.mk>
