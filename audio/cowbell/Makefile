# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	cowbell
PORTVERSION=	0.2.7.1
PORTREVISION=	12
CATEGORIES=	audio gnome
MASTER_SITES=	http://more-cowbell.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Elegant music organizer

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

USES=		gmake pathfix gettext iconv
USE_GNOME=	gnomeprefix intltool gtksharp20
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|.so.*"|.so"|g' ${WRKSRC}/cowbell.exe.config

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
