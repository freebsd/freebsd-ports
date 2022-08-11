PORTNAME=	lbreakout2
PORTVERSION=	2.6.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/${PORTVERSION:R}:1 \
		LOCAL/rene/${PORTNAME}:2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:1 \
		${PORTNAME}.png:2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breakout-style arcade game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake sdl
USE_SDL=	mixer net sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sdl-net \
		--localstatedir=/var/games \
		--with-docdir=${PREFIX}/share/doc

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --L_opts)

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^icondir/s|icons|pixmaps| ; \
		 /^icon_DATA/s|48.gif|2.png| ; \
		 /Icon=/s|$$(datadir).*.gif|lbreakout2|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/LDADD =/s|$$| @INTLLIBS@| ; \
		 s|: install-data-local|:|' ${WRKSRC}/client/Makefile.in
	@${REINPLACE_CMD} -e \
		'/LDADD =/s|$$| @INTLLIBS@|' ${WRKSRC}/server/Makefile.in

pre-build:
	${CP} ${DISTDIR}/${PORTNAME}.png ${WRKSRC}

post-install:
	(cd ${WRKSRC}/client && ${INSTALL_DATA} empty.hscr \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
