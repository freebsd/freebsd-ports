# New ports collection makefile for:	imlib2_loaders
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2_loaders
PORTVERSION=	1.1.1
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		edb.1:${PORTSDIR}/databases/edb \
		eet.9:${PORTSDIR}/devel/eet

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
