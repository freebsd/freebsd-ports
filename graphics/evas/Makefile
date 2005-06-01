# New ports collection makefile for:	evas
# Date created:		24 Oct 2000
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	evas
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	enlightenment

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hardware-accelerated canvas API for X-Windows

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_FREETYPE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1 \
			  -I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--disable-gl
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
