# New ports collection makefile for:	lasi
# Date created:		June 2006
# Whom:			giffunip
#
# $FreeBSD$
#    $MCom: ports/devel/lasi/Makefile,v 1.1 2006/10/04 20:25:40 ahze Exp $

PORTNAME=	lasi
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.unifont.org/lasi/download/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	C++ stream output interface for creating Postscript documents

USE_GNOME=	pango pkgconfig
USE_AUTOTOOLS=	libltdl:15
GNU_CONFIGURE=	yes
PKG_CONFIG_PATH=	${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PKG_CONFIG_PATH}

USE_LDCONFIG=	yes

.include <bsd.port.mk>
