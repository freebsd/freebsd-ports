# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	aalib
DISTVERSION=	1.4rc5
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/aa-project/aa-lib/1.4rc5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII art library

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool localbase makeinfo
WRKSRC=		${WRKDIR}/${PORTNAME}-1.4.0
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INFO=		aalib

OPTIONS_MULTI=		DRIVERS
OPTIONS_MULTI_DRIVERS=	X11 NCURSES SLANG
OPTIONS_DEFAULT=	NCURSES

DRIVERS_DESC=		Drives selection

X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_WITH=	x11-driver=yes
NCURSES_USES=		ncurses
NCURSES_CONFIGURE_WITH=	curses-driver=yes
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_WITH=	slang-driver=yes

post-extract:
	@${RM} ${WRKSRC}/doc/aalib.info*

post-patch:
	@${RM} ${WRKSRC}/config.cache
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|MAKEINFO=makeinfo|MAKEINFO="${MAKEINFO} --no-split"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|AC_DEFUN(AM_PATH_AALIB|AC_DEFUN([AM_PATH_AALIB]|g' \
		${WRKSRC}/aalib.m4
	@${FIND} ${WRKSRC} \( -name '*.[ch]' \! -name acconfig.h \) \
		| ${XARGS} ${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaa.so

.include <bsd.port.mk>
