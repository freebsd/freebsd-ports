# Created by: pgs (original)
# $FreeBSD$

PORTNAME=	xbl
PORTVERSION=	1.1.6
CATEGORIES=	games
MASTER_SITES=	http://perso.univ-lyon1.fr/thierry.excoffier/XBL/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D block-dropping game

LICENSE=	GPLv1+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_IMAKE="" ac_cv_prog_XMKMF=""
MAKE_ARGS=	USE_SETGID="" \
		GROUP_GID="" \
		RESOURCEDIR="${PREFIX}/lib/X11/app-defaults" \
		BINDIR="${PREFIX}/bin" \
		SCOREDIR="${PREFIX}/lib/X11/xbl" \
		MANPATH="${MANPREFIX}/man" \
		LIBS="-lm -lX11" \
		LDOPTIONS="${LDFLAGS}"

CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|@CFLA@ -g|@CFLA@|g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bl ${STAGEDIR}${PREFIX}/bin/xbl
	${INSTALL_MAN} ${WRKSRC}/xbl.man ${STAGEDIR}${MANPREFIX}/man/man1/xbl.1
	${INSTALL_DATA} ${WRKSRC}/Xbl.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Xbl
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xbl
	${INSTALL_DATA} ${WRKSRC}/Xbl.ad ${STAGEDIR}${PREFIX}/lib/X11/xbl/Xbl
	${INSTALL_DATA} ${WRKSRC}/*.gif ${STAGEDIR}${PREFIX}/lib/X11/xbl
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${PREFIX}/lib/X11/xbl

.include <bsd.port.mk>
