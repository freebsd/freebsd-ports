# New ports collection makefile for:   cdplay
# Version required:    0.92
# Date created:        8 July 1997
# Whom:                Antti Kaipila <anttik@iki.fi>
#
# $Id: Makefile,v 1.2 1998/01/05 17:12:11 vanilla Exp $
#

DISTNAME=	cdplay-0.92
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.one.sci.fi/pub/cdplay/

MAINTAINER=    anttik@iki.fi

pre-patch:
	@${GUNZIP_CMD} ${WRKSRC}/cdplay.1.gz

post-patch:
	@${GZIP_CMD} ${WRKSRC}/cdplay.1

.include <bsd.port.mk>
