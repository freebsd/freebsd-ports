# ex:ts=8
# Ports collection makefile for:	dxf2fig
# Date created:			Aug 26, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dxf2fig
PORTVERSION=	2.07
CATEGORIES=	cad
MASTER_SITES=	http://ta.twi.tudelft.nl/ftp/dv/lemmens/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DXF to FIG converter

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/dxf2fig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
