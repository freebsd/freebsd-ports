# New ports collection makefile for:	emboss
# Date created:		31 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	emboss
PORTVERSION=	1.0.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.uk.embnet.org/pub/EMBOSS/
DISTNAME=	EMBOSS-${PORTVERSION}

MAINTAINER=	johann@egenetics.com

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/gd" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
