PORTNAME=	xtrader
PORTVERSION=	0.99.9
PORTREVISION=	10
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Technical analysis program for financial instruments
WWW=		https://xtrader.sourceforge.net/

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=	2024-02-29

LIB_DEPENDS=	libptypes.so:devel/ptypes \
		libfltk.so.1:x11-toolkits/fltk

USES=		gmake xorg
USE_XORG=	x11 xpm

MAKEFILE=	Makefile.linux

CFLAGS+=	--std=c++14

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

PLIST_FILES=	bin/xtrader \
		%%DATADIR%%/sample.xt

post-patch:
	${REINPLACE_CMD} -e 's|char|const char|' \
	    ${WRKSRC}/xtrader/src/Resource.cpp
	${REINPLACE_CMD} -e 's|static char|static const char|' \
	    ${WRKSRC}/xtrader/src/Resource.h
	${REINPLACE_CMD} -e 's|int(data)|(unsigned long)data|' \
	    ${WRKSRC}/xtrader/src/gui/XTrader.h
	${FIND} ${WRKSRC} -type f -name "*.cpp" -o -name "*.h" | ${XARGS} \
	   ${REINPLACE_CMD} -e '/^#include <FL/s|.h>$$|.H>|; s|fl_file_chooser|Fl_File_Chooser|g'

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/sample.xt ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/xtrader ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
