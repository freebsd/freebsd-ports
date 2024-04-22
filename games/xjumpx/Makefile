PORTNAME=	xjumpx
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://fenix.ne.jp/~cdrtk/soft/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Improved version of xjump

LICENSE=	BSD2CLAUSE

MAKE_ENV=	X11BASE=${LOCALBASE}
USES=		xorg
USE_XORG=	x11 xext xpm xaw xmu xt

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xjumpx ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xjumpx
	${CP} ${WRKSRC}/XJumpX.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XJumpX
	${INSTALL_MAN} ${WRKSRC}/xjumpx.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man1/xjumpx.1

.include <bsd.port.mk>
