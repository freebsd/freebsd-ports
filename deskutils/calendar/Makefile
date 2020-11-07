# $FreeBSD$

PORTNAME=	calendar
DISTVERSION=	0.9
CATEGORIES=	deskutils

MAINTAINER=	se@FreeBSD.org
COMMENT=	Port of the FreeBSD calendar program

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/share/calendar/calendar.all:deskutils/calendar-data

USE_GITHUB=	yes
GH_ACCOUNT=	stesser

CFLAGS+=	-D_PATH_LOCALBASE='\"${LOCALBASE}\"'
LDFLAGS+=	-lm -lutil

PLIST_FILES=	bin/calendar \
		share/man/man1/calendar.1.gz

OPTIONS_DEFINE=	NLS
NLS_CFLAGS=	-DWITH_ICONV

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/calendar ${STAGEDIR}${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/calendar.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
