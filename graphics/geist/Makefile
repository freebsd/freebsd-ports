# New ports collection makefile for:	geist
# Date created:				24 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	geist
PORTVERSION=	0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ishmael27@home.com

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib" \
		XML_CONFIG="${XML_CONFIG}"

.include <bsd.port.mk>
