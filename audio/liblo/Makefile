# New ports collection makefile for:	liblo
# Date created:		2006-12-04
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	liblo
PORTVERSION=	0.24
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	liblo

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	Lightweight Open Sound Control implementation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
