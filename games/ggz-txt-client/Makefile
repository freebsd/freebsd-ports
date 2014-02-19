# Created by: ijliao
# $FreeBSD$

PORTNAME=	ggz-txt-client
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Console (Text) Frontend

USES=		readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread -lexpat

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ARGS=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's|_LDADD =|_LDADD = $$(LIB_GGZCORE)|' \
		${WRKSRC}/tttxt/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ggz
	@${INSTALL_DATA} ${WRKSRC}/tttxt/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/tttxt.dsc

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
