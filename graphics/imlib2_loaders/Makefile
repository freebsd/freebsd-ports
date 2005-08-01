# New ports collection makefile for:	imlib2_loaders
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2_loaders
PORTVERSION=	1.2.1.004
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		edb.1:${PORTSDIR}/databases/edb \
		eet.9:${PORTSDIR}/devel/eet

USE_LIBTOOL_VER=	15
USE_GNOME=	gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LIBS="-L${PREFIX}/lib"

.include <bsd.port.mk>
