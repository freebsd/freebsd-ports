# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	trophy
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Single player racing game

LICENSE=	GPLv2

LIB_DEPENDS=	clanCore:${PORTSDIR}/devel/clanlib1

USES=		pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN6=	trophy.6

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
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
