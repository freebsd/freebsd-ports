# Created by: Alexander Kuehn <freebsd@nagilum.org>
# $FreeBSD$

PORTNAME=	zopfli
PORTVERSION=	1.0.0
CATEGORIES=	archivers
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	freebsd@nagilum.org
COMMENT=	Zopfli Compression Algorithm

LICENSE=	APACHE20

USES=		zip
PLIST_FILES=	bin/zopfli

do-build:
	${CC} -O2 -W -Wall -Wextra -ansi -pedantic -lm \
	  ${CFLAGS} ${EXTRA_DEFINES} -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/src/${PORTNAME}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
