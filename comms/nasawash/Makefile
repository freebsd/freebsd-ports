# Created by: db
# $FreeBSD$

PORTNAME=	nasawash
PORTVERSION=	0.50
CATEGORIES=	comms hamradio
MASTER_SITES=	ftp://ftp.amsat.org/amsat/software/Linux/
DISTNAME=	nasawash
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio keplerian file cleanup program

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}

PLIST_FILES=	bin/nasawash
PORTDOCS=	nasawash.txt nasawash.upd

NO_STAGE=	yes
do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o ${WRKSRC}/nasawash.o ${WRKSRC}/nasawash.c
	${CC} -o ${WRKSRC}/nasawash ${WRKSRC}/nasawash.o ${LIBS}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/nasawash ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
