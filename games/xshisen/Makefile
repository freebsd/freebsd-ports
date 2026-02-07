PORTNAME=	xshisen
PORTVERSION=	1.51
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	TsurutaniNaoki@gmail.com
COMMENT=	Shisen-sho puzzle game for X11

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe xorg
USE_CXXSTD=	c++14
USE_XORG=	ice sm x11 xmu xpm xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sharedstatedir="${DATADIR}"

INSTALL_TARGET=	install-prog

OPTIONS_DEFINE=		MOTIF
OPTIONS_DEFAULT=	MOTIF

MOTIF_USES=		motif
MOTIF_CONFIGURE_WITH=	motif

post-patch:
	@${REINPLACE_CMD} -e \
		's|XSHISEN_VERSION|${PORTVERSION}|g' ${WRKSRC}/lang/XShisen.ad*

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/xshisen.6 \
		${STAGEDIR}${PREFIX}/share/man/man6/xshisen.6
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/ja/man6
	${INSTALL_MAN} ${WRKSRC}/man/xshisen.6.ja_JP.eucJP \
		${STAGEDIR}${PREFIX}/share/man/ja/man6/xshisen.6
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/lang/XShisen.ad \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XShisen
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/lang/XShisen.ad.ja_JP.eucJP \
		${STAGEDIR}${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/XShisen

.include <bsd.port.mk>
