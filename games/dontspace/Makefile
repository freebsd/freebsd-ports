PORTNAME=	dontspace
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games tk
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JACOBY/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire game for X11 modeled after Free Space

USES=		tk shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${PREFIX}/share/games
CONFIGURE_ENV=	WISHX=${WISH}
SHEBANG_FILES=	*.tcl
tk_OLD_CMD=	/usr/dist/bin/wishx
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -E 's,(BIN|LIB|MAN)DIR),DESTDIR)$$(&,g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
