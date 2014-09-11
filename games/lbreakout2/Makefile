# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	lbreakout2
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breakout-style arcade game

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		gmake
USE_SDL=	mixer net sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sdl-net \
		--localstatedir=/var/games \
		--with-docdir=${PREFIX}/share/doc

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --L_opts)

PKGDEINSTALL=	${PKGINSTALL}

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/if test/s|==|=|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/icons|/pixmaps|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/LDADD =/s|$$| @INTLLIBS@| ; \
		 s|: install-data-local|:|' ${WRKSRC}/client/Makefile.in
	@${REINPLACE_CMD} -e \
		'/LDADD =/s|$$| @INTLLIBS@|' ${WRKSRC}/server/Makefile.in

post-install:
	(cd ${WRKSRC}/client && ${INSTALL_DATA} empty.hscr \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
