# New ports collection makefile for:	cowbell
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	cowbell
PORTVERSION=	0.2.7.1
PORTREVISION=	11
CATEGORIES=	audio gnome
MASTER_SITES=	http://more-cowbell.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An elegant music organizer

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib

USE_GNOME=	gnomehack gnomeprefix gnometarget intltool gtksharp20
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|.so.*"|.so"|g' ${WRKSRC}/cowbell.exe.config

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
