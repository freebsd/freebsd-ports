# New ports collection makefile for:	gpaint
# Date created:				18 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpaint
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	http://www.atai.org/gpaint/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small-scale painting program for GNOME

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomeprint
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
