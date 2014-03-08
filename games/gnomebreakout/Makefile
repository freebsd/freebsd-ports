# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnomebreakout
PORTVERSION=	0.5.3
PORTREVISION=	11
CATEGORIES=	games gnome
MASTER_SITES=	http://www.users.on.net/~mipearson/
DISTNAME=	gnome-breakout-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME version of the classic breakout game

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USES=		pathfix pkgconfig
USE_GNOME=	gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|games.games|root:games|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-Werror||g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@GETTEXT_PACKAGE@|@PACKAGE@|g' ${WRKSRC}/po/Makefile.in.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGNOME_DISABLE_DEPRECATED||g ; s|-DGTK_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
