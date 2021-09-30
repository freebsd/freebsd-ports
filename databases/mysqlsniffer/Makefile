# Created by: Frederic Hardy <frederic.hardy@mageekbox.net>

PORTNAME=	mysqlsniffer
PORTVERSION=	1.2
CATEGORIES=	databases

MAINTAINER=	frederic.hardy@mageekbox.net
COMMENT=	Tcpdump clone specifically for MySQL

DEPRECATED=	Development discontinued upstream, doesn't build on recent FreeBSD
EXPIRATION_DATE=2021-10-30
BROKEN_FreeBSD_13=	ld: error: duplicate symbol: decoded_len
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: decoded_len

WRKSRC_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/mysqlsniffer

USE_GITHUB=	yes
GH_ACCOUNT=	daniel-nichter
GH_PROJECT=	hackmysql.com
GH_TAGNAME=	ddb6f92

do-build:
	${CC} ${CFLAGS} -lpcap -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/mysqlsniffer.c ${WRKSRC}/packet_handlers.c \
			${WRKSRC}/misc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
