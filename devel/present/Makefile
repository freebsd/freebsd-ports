# New ports collection makefile for:	present
# Date created:		2005-06-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/present/Makefile,v 1.8 2006/01/31 22:17:59 ahze Exp $
#

PORTNAME=	present
PORTVERSION=	0.0.3
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for reading Microsoft PowerPoint(tm) documents

LIB_DEPENDS=	goffice-1.2:${PORTSDIR}/devel/goffice1

DEPRECATED=	depends on libgsf_gnome (via goffice1) which going away.
EXPIRATION_DATE=2013-04-12

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack intlhack ltverhack

.include <bsd.port.mk>
