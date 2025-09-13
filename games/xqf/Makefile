PORTNAME=	xqf
PORTVERSION=	1.0.6.2
PORTREVISION=	3
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server browser for many popular 3D action games
WWW=		http://www.linuxgames.com/xqf/

BROKEN=		Fails to build, ld: error: non-exported symbol 'environ' in '/usr/lib/crt1.o' is referenced by DSO '/lib/libc.so.7'
EXPIRATION_DATE=2025-10-13

RUN_DEPENDS=	qstat:games/qstat

USES=		autoreconf gettext gmake gnome pkgconfig xorg
USE_GNOME=	intlhack gdkpixbuf gdkpixbuf2xlib
USE_XORG=	x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	XQF

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	GTK2 BZIP2 DOCS
OPTIONS_DEFAULT=GTK2 BZIP2

GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ENABLE=	gtk2

BZIP2_CONFIGURE_ENABLE=	bzip2

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
