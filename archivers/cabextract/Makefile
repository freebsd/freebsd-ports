# New ports collection makefile for:	cabextract
# Date Created:				30 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cabextract
PORTVERSION=	0.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.kyz.uklinux.net/downloads/
EXTRACT_SUFX=	.c.gz
EXTRACT_ONLY=

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}

SRCFILE=	${WRKSRC}/${PORTNAME}.c
PROGFILE=	${SRCFILE:S/.c$//}

post-extract:
	@${GZIP_CMD} -d -c ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${SRCFILE}

do-build:
	${CC} ${CFLAGS} -o ${PROGFILE} ${SRCFILE}

do-install:
	${INSTALL_PROGRAM} ${PROGFILE} ${PREFIX}/bin

.include <bsd.port.mk>
