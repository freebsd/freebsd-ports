# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	lbreakout2
PORTVERSION=	2.6.5
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breakout-style arcade game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gif2png:graphics/gif2png
LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake
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
	(cd ${WRKSRC} && ${CAT} lbreakout48.gif | gif2png -O -f \
		> lbreakout2.png)

post-install:
	(cd ${WRKSRC}/client && ${INSTALL_DATA} empty.hscr \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
