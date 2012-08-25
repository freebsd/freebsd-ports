# New Ports collection makefile for:	glightoff
# Date created:		21 April 2012
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	glightoff
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple (but not so easy to solve!) puzzle game

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_XORG=	x11

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	NLS
NLS_DESC=	Native Language Support via gettext
OPTIONS_DEFAULT=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-configure:
.if empty(PORT_OPTIONS:MNLS)
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
