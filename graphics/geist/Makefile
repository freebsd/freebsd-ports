# New ports collection makefile for:	geist
# Date created:				24 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	geist
PORTVERSION=	0.0.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An object-based image creation/layout application

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib" \
		XML_CONFIG="${XML_CONFIG}"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/test.xml

.include <bsd.port.mk>
