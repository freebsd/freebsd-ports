# New ports collection makefile for:	vo-aacenc
# Date created:		23 Jun 2011
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vo-aacenc
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/opencore-amr/${PORTNAME}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	VisualOn AAC encoder library

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
WITH_FBSD10_FIX=yes

post-patch:
	@${REINPLACE_CMD} -E -e \
	's|^pkgconfigdir = .*|pkgconfigdir = $$(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
