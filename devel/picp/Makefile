# New ports collection makefile for:    picp
# Date created:         25 October 2002
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	picp
PORTVERSION=	0.6.8
CATEGORIES=	devel
MASTER_SITES=	http://home.pacbell.net/theposts/picmicro/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Driver for the Microchip Picstart Plus development programmer

PLIST_FILES=	bin/picp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picp ${PREFIX}/bin

.include <bsd.port.mk>
