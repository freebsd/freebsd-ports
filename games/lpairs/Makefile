# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lpairs
PORTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classical memory game

GNU_CONFIGURE=	yes
USE_SDL=	sdl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
PLIST_FILES+=	share/locale/de/LC_MESSAGES/lpairs.mo
.else
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS =/ s|$$| $${INTLLIBS}|' \
		${WRKSRC}/lpairs/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(inst_dir=\).*|\1$$datarootdir/lpairs|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
