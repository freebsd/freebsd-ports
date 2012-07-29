# New ports collection makefile for:	gtetrinet
# Date created:				27 Feb 2000
# Whom:					Dan Papasian <bugg@bugg.strangled.net>
#
# $FreeBSD$

PORTNAME=	gtetrinet
PORTVERSION=	0.7.11
PORTREVISION=	9
CATEGORIES=	games gnome ipv6
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version of the popular TetriNET multiplayer Tetris clone

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	esound gnomehack gnomeprefix libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --enable-ipv6

MAN6=		gtetrinet.6
GCONF_SCHEMAS=	gtetrinet.schemas

pre-configure:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]prefix[)]/games|{bindir}|g; /_DISABLE_DEPRECATED/d'

.include <bsd.port.mk>
