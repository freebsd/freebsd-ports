# New ports collection makefile for:	entice
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	entice
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ny.us.rasterman.com/files/

DEPRECATED=	"CVS snapshot on master site gone, no releases from Enlightenment"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer written using libraries for Enlightenment 0.17 development

LIB_DEPENDS=	ecore.0:${PORTSDIR}/x11/ecore \
		evas.6:${PORTSDIR}/graphics/evas

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
