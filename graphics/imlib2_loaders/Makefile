# New ports collection makefile for:	imlib2_loaders
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2_loaders
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		edb.1:${PORTSDIR}/databases/edb

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
