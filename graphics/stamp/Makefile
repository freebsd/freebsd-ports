# New ports collection makefile for:	stamp
# Date created:	11 August 1998
# Whom:		Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	stamp
PORTVERSION=	2.0.8
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	stamp

MAINTAINER=	billf@FreeBSD.org
COMMENT=	Adds a graphical, configurable timestamp to a grayscale image

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	unfortunatly

.include <bsd.port.mk>
