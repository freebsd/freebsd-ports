# ports collection makefile for:	nasawash
# Date created:		4 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	nasawash
PORTVERSION=	0.50
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.amsat.org/amsat/software/Linux/
DISTNAME=	nasawash
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio keplerian file cleanup program

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}

PLIST_FILES=	bin/nasawash
PORTDOCS=	nasawash.txt nasawash.upd

do-build:
	${CC} ${CPPFLAGS} ${CFLAGS} -c -o ${WRKSRC}/nasawash.o ${WRKSRC}/nasawash.c
	${CC} -o ${WRKSRC}/nasawash ${WRKSRC}/nasawash.o ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nasawash ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "nasawash docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
