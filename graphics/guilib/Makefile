# New ports collection makefile for:	guilib
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guilib
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/
DISTNAME=	GUIlib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A very simple GUI framework for use with SDL

USE_SDL=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
