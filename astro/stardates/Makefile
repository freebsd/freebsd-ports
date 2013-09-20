# Created by: freebsd-ports@henrik.synth.no
# $FreeBSD$

PORTNAME=	stardates
PORTVERSION=	1.6.1
CATEGORIES=	astro
MASTER_SITES=	ftp://ftp.cc.umanitoba.ca/startrek/stardates-pgms/ \
		http://trek.starshine.org/downlink/utilities/ \
		http://trek-stage.parts-unknown.org/downlink/

MAINTAINER=	freebsd-ports@henrik.synth.no
COMMENT=	Displays date in 5 formats (including stardate of course)

NO_STAGE=	yes
MAN1=		stardate.1
PLIST_FILES=	bin/stardate

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/stardate.c -o ${WRKSRC}/stardate

do-install:
	${INSTALL} ${WRKSRC}/stardate ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/stardate.1 ${MAN1PREFIX}/man/man1/stardate.1

.include <bsd.port.mk>
