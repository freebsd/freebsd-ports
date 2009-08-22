# New ports collection makefile for:	lpairs
# Date created:		12 Sep 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lpairs
PORTVERSION=	1.0.4
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/1.0

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classical memory game

GNU_CONFIGURE=	yes
USE_SDL=	sdl
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$| $${INTLLIBS}|' \
		${WRKSRC}/lpairs/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(inst_dir=\).*|\1$$datarootdir/lpairs|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
