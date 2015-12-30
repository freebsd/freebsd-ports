# Created by: Frederic Hardy <frederic.hardy@mageekbox.net>
# $FreeBSD$

PORTNAME=	mysqlsniffer
PORTVERSION=	1.2
CATEGORIES=	databases

MAINTAINER=	frederic.hardy@mageekbox.net
COMMENT=	Tcpdump clone specifically for MySQL

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
