# New Ports collection makefile for:	glightoff
# Date created:		21 April 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	glightoff
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GLightOff is a simple (but not so easy to solve!) puzzle game

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 intltool
USE_XORG=	x11

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

OPTIONS=	NLS	"Enable gettext support" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-configure:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} 's|src po|src|' ${WRKSRC}/Makefile
.endif

post-install:
# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
