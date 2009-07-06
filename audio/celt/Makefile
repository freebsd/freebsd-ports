# New ports collection makefile for:	celt
# Date created:		2009-02-11
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	celt
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/celt/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	The CELT ultra-low delay audio codec

LIB_DEPENDS=	ogg.6:${PORTSDIR}/audio/libogg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
USE_GCC=	4.2+

.include <bsd.port.mk>
