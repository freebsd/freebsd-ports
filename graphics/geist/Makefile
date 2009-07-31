# New ports collection makefile for:	geist
# Date created:				24 Oct 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	geist
PORTVERSION=	0.0.3
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An object-based image creation/layout application

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

XML_CONFIG?=	${LOCALBASE}/bin/xml2-config
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_EFL=	imlib2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		XML_CONFIG="${XML_CONFIG}"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/test.xml

.include <bsd.port.mk>
