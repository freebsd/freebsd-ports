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
COMMENT=	Graphics tool to split up a JPEG image and provide HTML for the slices

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

PLIST_FILES=	bin/jslice

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jslice ${PREFIX}/bin

.include <bsd.port.mk>
