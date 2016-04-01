# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnono
PORTVERSION=	1.9.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uno card game

USE_GNOME=	gtk20 libgnomeui intltool
USES=		gettext gmake pkgconfig tar:bzip2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|-DG.*_DISABLE_DEPRECATED||g' -e 's|-Werror||g'
	@${REINPLACE_CMD} -e 's|glib/garray.h|glib.h|g' \
		-e 's|glib/gmessages.h|glib.h|g' \
		-e 's|glib/gtypes.h|glib.h|g' \
		-e 's|glib/gmem.h|glib.h|g' \
		-e 's|glib/gmain.h|glib.h|g' \
		${WRKSRC}/src/ai.[ch] \
		${WRKSRC}/src/cards.[ch] \
		${WRKSRC}/src/game.[ch] \
		${WRKSRC}/src/interface.[ch] \
		${WRKSRC}/src/main.c \
		${WRKSRC}/src/players.[ch] \
		${WRKSRC}/src/preferences.[ch]

.include <bsd.port.mk>
