# New ports collection makefile for:	monkeybubble
# Date created:				06 October 2003
# Whom:					Adam Weinberger
#
# $FreeBSD$
#

PORTNAME=	monkeybubble
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	games gnome
MASTER_SITES=	http://home.gna.org/monkeybubble/downloads/
DISTNAME=	monkey-bubble-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 Puzzle Bobble clone with monkeys

USE_GNOME=	gnomedocutils gnomehack gnomeprefix gnometarget intlhack \
		librsvg2 libgnomeui
USE_GSTREAMER=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes

GCONF_SCHEMAS=	monkey-bubble.schemas

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-g -O2||g ; \
		 s|-Werror||g'

.include <bsd.port.post.mk>
