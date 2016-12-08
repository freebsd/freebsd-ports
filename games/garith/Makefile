# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	garith
PORTVERSION=	2.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.cnm-vra.com/micah/garith/
# Latest version (2.3.1) does not build with gtk 1.2.10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arithmetic quiz program for X Window System

USE_GNOME=	gtk12
WRKSRC=		${WRKDIR}/garith
CFLAGS+=	`${GTK_CONFIG} --cflags`
LDFLAGS+=	`${GTK_CONFIG} --libs`
PORTDOCS=	BUGS HISTORY README TODO
PLIST_FILES=	bin/garith

post-patch:
	@${REINPLACE_CMD} -e 's|gldouble|double|;/gnome/d;/all.*apps/d'\
		${WRKSRC}/garith.c

do-build:
	cd ${WRKSRC}&&${CC} ${CFLAGS} -o garith garith.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/garith ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
