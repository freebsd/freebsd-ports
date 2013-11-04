# Created by: Adam Weinberger
# $FreeBSD$

PORTNAME=	monkeybubble
PORTVERSION=	0.4.0
PORTREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	http://home.gna.org/monkeybubble/downloads/
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

LICENSE=	GPLv2

USES=		pathfix gmake pkgconfig
USE_GNOME=	gnomedocutils gnomeprefix intlhack \
		librsvg2 libgnomeui
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	monkey-bubble.schemas

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-g -O2||g ; \
		 s|-Werror||g'
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/net/message-handler.c \
		${WRKSRC}/src/net/simple-server.c \
		${WRKSRC}/src/ui/main.c

.include <bsd.port.mk>
