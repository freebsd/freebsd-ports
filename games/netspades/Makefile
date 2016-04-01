# Created by: Frank Laszlo <laszlof@freebsdmatrix.net>
# $FreeBSD$

PORTNAME=	NetSpades
PORTVERSION=	4.2.0
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	TUCOWS/x11/entertain \
		http://www.ece.rice.edu/~brentmh/spades/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very popular card game for 1-4 players over a network

LICENSE=	GPLv2+

OPTIONS_DEFINE=	GTK1 SLANG
OPTIONS_DEFAULT=	GTK1 SLANG

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spadesd man/man6/spadesd.6.gz

GTK1_USE=		GNOME=gtk12
GTK1_CONFIGURE_OFF=	--without-gtk
GTK1_PLIST_FILES=	bin/gspades man/man6/gspades.6.gz

SLANG_USES=		readline ncurses
SLANG_CONFIGURE_OFF=	--without-slang
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_LDFLAGS=		-lncurses
SLANG_PLIST_FILES=	bin/slspades man/man6/slspades.6.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK1}
DESKTOP_ENTRIES="GSpades" "" "" "gspades" "" ""
.endif

post-patch:
.for i in engine_func.c gtk_connect.c listen.c sl_io.c
	@${REINPLACE_CMD} -e \
		's| log| ns_log|g' ${WRKSRC}/src/${i}
.endfor

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} spadesd \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} spadesd.6 \
		${STAGEDIR}${MANPREFIX}/man/man6)
.if ${PORT_OPTIONS:MGTK1}
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} gspades \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} gspades.6 \
		${STAGEDIR}${MANPREFIX}/man/man6)
.endif
.if ${PORT_OPTIONS:MSLANG}
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} slspades \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} slspades.6 \
		${STAGEDIR}${MANPREFIX}/man/man6)
.endif

.include <bsd.port.mk>
