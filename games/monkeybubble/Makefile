# Created by: Adam Weinberger
# $FreeBSD$

PORTNAME=	monkeybubble
PORTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	games gnome
MASTER_SITES=	http://home.gna.org/monkeybubble/downloads/
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gnomedocutils gnomeprefix intlhack \
		librsvg2 libgnomeui
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm
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
