# New ports collection makefile for:	insert
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	jslice
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.pldaniels.com/jslice/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jslice ${PREFIX}/bin

.include <bsd.port.mk>
