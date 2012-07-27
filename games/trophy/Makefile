# New ports collection makefile for:	trophy
# Date created:			2004-01-24
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	trophy
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A single player racing game

LICENSE=	GPLv2

LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN6=	trophy.6

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e "/^icondir =/s,icons,pixmaps," \
		${WRKSRC}/resources/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR} && \
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
