# Created by: ijliao
# $FreeBSD$

PORTNAME=	ggz-txt-client
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Console (Text) Frontend

USES=		gettext readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
USE_GGZ=	client

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread -lexpat

post-patch:
	@${REINPLACE_CMD} -e 's|_LDADD =|_LDADD = $$(LIB_GGZCORE)|' \
		${WRKSRC}/tttxt/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ggz
	@${INSTALL_DATA} ${WRKSRC}/tttxt/module.dsc ${STAGEDIR}/${PREFIX}/share/ggz/tttxt.dsc
	${RM} ${STAGEDIR}${PREFIX}/etc/ggz.modules

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
