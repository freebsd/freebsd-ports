# New ports collection makefile for:	cowbell
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	cowbell
PORTVERSION=	0.2.6.2
CATEGORIES=	audio gnome
MASTER_SITES=	http://more-cowbell.org/releases/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	An elegant music organizer

LIB_DEPENDS=	tag:${PORTSDIR}/audio/taglib
BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		mono:${PORTSDIR}/lang/mono

USE_GNOME=	gnomehack gnomeprefix gnometarget intltool
USE_X_PREFIX=	yes
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
