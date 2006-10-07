# New ports collection makefile for:	liblrdf
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblrdf
DISTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	SF/lrdf

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	RDF library with support for LADSPA plugins

LIB_DEPENDS=	raptor.2:${PORTSDIR}/textproc/raptor

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s!=.*!= ${PREFIX}/libdata/pkgconfig!' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
