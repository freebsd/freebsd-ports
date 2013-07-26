# New ports collection makefile for:	geglmm
# Date created:		2010-01-25
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geglmm
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	C++ bindings for GEGL

LIB_DEPENDS=	gegl-0.1.107:${PORTSDIR}/graphics/gegl \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

BROKEN=		does not compile

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USES=	pathfix
USE_PERL5_BUILD=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
