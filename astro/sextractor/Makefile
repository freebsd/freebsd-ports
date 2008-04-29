# New ports collection makefile for:	sextractor
# Date created:		22 April 2008
# Whom:			Mathias Monnerville <mathias@monnerville.com>
#
## $FreeBSD$
#

PORTNAME=		sextractor
PORTVERSION=	2.5.0
CATEGORIES=		astro
MASTER_SITES=	ftp://ftp.iap.fr/pub/from_users/bertin/sextractor/ \
		http://download.gna.org/kanicule/freebsd/distfiles/

MAINTAINER=	mathias@monnerville.com
COMMENT=	Catalogue of objects builder from astronomical images

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	sex.1
MANX=	sex.x

OPTIONS=	STATIC "Use static linking" on

.include <bsd.port.pre.mk>

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--enable-static
.endif

.include <bsd.port.post.mk>
