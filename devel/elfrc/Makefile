# New ports collection makefile for:	elfrc
# Date created:				13 July 2007
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	elfrc
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	http://ktown.kde.org/~frerich/

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Resource compiler for ELF systems

PLIST_FILES=	bin/elfrc
PORTDOCS=	README

do-build:
	@${ECHO} '#define ELFRC_VERSION "${PORTVERSION}"' > ${WRKSRC}/config.h
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/elfrc ${WRKSRC}/elfrc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elfrc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
