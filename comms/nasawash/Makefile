# Created by: db
# $FreeBSD$

PORTNAME=	nasawash
PORTVERSION=	0.50
CATEGORIES=	comms hamradio
MASTER_SITES=	ftp://ftp.amsat.org/amsat/software/Linux/ \
		LOCAL/db
DISTNAME=	nasawash

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio keplerian file cleanup program

LICENSE=	NASAWASH
LICENSE_NAME=	NASAWASH License
LICENSE_TEXT=	Copyright 1995 Paul Williamson, KB5MU.  All Rights Reserved. \
		You may use this program freely for non-commercial purposes.  This \
		program may be distributed freely, provided that it is distributed \
		without modification and with all the associated documentation files.
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		tar:tgz
PLIST_FILES=	bin/nasawash
PORTDOCS=	nasawash.txt nasawash.upd

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o ${WRKSRC}/nasawash.o ${WRKSRC}/nasawash.c
	${CC} ${LDFLAGS} -o ${WRKSRC}/nasawash ${WRKSRC}/nasawash.o ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nasawash ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
