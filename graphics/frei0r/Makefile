# New ports collection makefile for:	frei0r
# Date created:		17 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frei0r
PORTVERSION=	1.1.19
DISTVERSIONPREFIX=	plugins-
CATEGORIES=	graphics
MASTER_SITES=	http://frei0r.kexbox.org/download/source/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Minimalistic plugin API for video effects

NO_BUILD=	yes
PLIST_FILES=	include/frei0r.h

post-extract:
	@${FIND} ${WRKSRC} -name .arch-ids -or -name {arch} | ${XARGS} ${RM} -rf

do-install:
	@${INSTALL_DATA} ${WRKSRC}/spec/frei0r.h ${PREFIX}/include/

.include <bsd.port.mk>
