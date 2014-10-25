# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	cowbell
PORTVERSION=	0.2.7.1
PORTREVISION=	12
CATEGORIES=	audio gnome
MASTER_SITES=	http://more-cowbell.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Elegant music organizer

LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib

BROKEN=		No more public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

USES=		gmake mono pathfix gettext iconv pkgconfig
USE_GNOME=	gnomeprefix intltool gtksharp20
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|.so.*"|.so"|g' ${WRKSRC}/cowbell.exe.config

.include <bsd.port.mk>
