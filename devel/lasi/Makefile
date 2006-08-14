# New ports collection makefile for:	lasi
# Date created:		June 2006
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	lasi
PORTVERSION=	1.0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.unifont.org/lasi/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ stream output interface for creating Postscript documents

USE_GCC=	3.2+
USE_GNOME=	pango pkgconfig
USE_AUTOTOOLS=	libltdl:15
GNU_CONFIGURE=	yes
PKG_CONFIG_PATH=	${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
