# New ports collection makefile for:	oonsoo
# Date created:		23rd June, 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	oonsoo
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.redlinelabs.com/pub/oonsoo/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A solitaire card game for X

PLIST_FILES=	bin/oonsoo
USE_XLIB=	yes

pre-patch:
	@${CP} ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/oonsoo ${PREFIX}/bin

.include <bsd.port.mk>
