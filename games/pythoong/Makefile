# New ports collection makefile for:	pythoong
# Date created:				24 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pythoong
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://perso.wanadoo.fr/christophe.cressend/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A snake-like game written for Gnome desktop

BUILD_DEPENDS=	xbmtopbm:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
