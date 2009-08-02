# New ports collection makefile for:	dotconf++
# Date created:		7 July 2005
# Whom:			Mark Starovoytov <mark_sf@kikg.ifmo.ru>
#
# $FreeBSD$
#

PORTNAME=	dotconfpp
PORTVERSION=	0.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://voodoo.com.ua/dotconfpp/
MASTER_SITE_SUBDIR=	dotconfpp
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mark_sf@kikg.ifmo.ru
COMMENT=	Configuration file parser written in C++

USE_AUTOTOOLS=	libtool:22

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/src/dotconfpp.h ${WRKSRC}/src/mempool.h

.include <bsd.port.mk>
