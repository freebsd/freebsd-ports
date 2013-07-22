# Created by: ijliao
# $FreeBSD$

PORTNAME=	ggz-txt-client
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Console (Text) Frontend

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

MAN6=	ggz-txt.6

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/share/ggz
	@${INSTALL_DATA} ${WRKSRC}/tttxt/module.dsc ${PREFIX}/share/ggz/tttxt.dsc

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
