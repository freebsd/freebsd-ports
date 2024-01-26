PORTNAME=	aalib
DISTVERSION=	1.4rc5
PORTREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	SF/aa-project/aa-lib/1.4rc5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII art library
WWW=		https://aa-project.sourceforge.net/aalib/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

WRKSRC=		${WRKDIR}/${PORTNAME}-1.4.0

INFO=		aalib

OPTIONS_DEFAULT=	NCURSES
OPTIONS_MULTI=		DRIVERS
OPTIONS_MULTI_DRIVERS=	X11 NCURSES SLANG

DRIVERS_DESC=		Drivers selection

NCURSES_USES=		ncurses
NCURSES_CONFIGURE_WITH=	curses-driver=yes
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_WITH=	slang-driver=yes
X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_WITH=	x11-driver=yes

post-patch:
	@${RM} ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|AC_DEFUN(AM_PATH_AALIB|AC_DEFUN([AM_PATH_AALIB]|g' \
		${WRKSRC}/aalib.m4
	@${FIND} ${WRKSRC} \( -name '*.[ch]' \! -name acconfig.h \) \
		| ${XARGS} ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaa.so

.include <bsd.port.mk>
