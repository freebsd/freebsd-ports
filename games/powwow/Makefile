# Ports collection Makefile for:	powwow
# Date created:				15 Nov 2004
# Whom:					Juraj Lutter <otis@sk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	powwow
PORTVERSION=	1.2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://Linuz.sns.it/pub/Linux/max/powwow/ \
		ftp://ftp.wilbury.sk/pub/FreeBSD/local/distfiles/
MASTER_SITE_SUBDIR=	games/muds

MAINTAINER=	otis@freebsd.sk
COMMENT=	Client to play MUDs

USE_REINPLACE=	yes

MAN6=		powwow.6

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/defines.h \
		${WRKSRC}/list.c ${WRKSRC}/main.c ${WRKSRC}/cmd2.c

do-build:
	cd ${WRKSRC} && POWWOW_DIR="${DATADIR}" ./make_it

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/powwow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/powwow.6 ${PREFIX}/man/man6
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.doc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/powwow.help ${DATADIR}

.include <bsd.port.mk>
