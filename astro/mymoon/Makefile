# New ports collection makefile for:	mymoon
# Date created:				24 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	mymoon
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://makemebad.net/geek/codes/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show latitude and longitude of the moon

LIB_DEPENDS=	nova:${PORTSDIR}/astro/libnova

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/mymoon

.include <bsd.port.mk>
