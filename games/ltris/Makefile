# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ltris
PORTVERSION=	1.0.19
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Tetris clone but a good one with bunch of cool features

USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
USES=		gmake
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/\/icons/\/pixmaps/g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/= @mixer_flag@/= @INTLLIBS@ @mixer_flag@/g ; \
		 s/--mode=666//g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's/^inline //' \
		${WRKSRC}/src/sdl.h ${WRKSRC}/src/tools.h

post-install:
	@${CHMOD} 2755 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:games ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} 0664 ${STAGEDIR}${DATADIR}/${PORTNAME}.hscr
	@${CHOWN} root:games ${STAGEDIR}${DATADIR}/${PORTNAME}.hscr

.include <bsd.port.mk>
