# New ports collection makefile for:	QWDtools
# Date created:				24 Sen 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	qwdtools
PORTVERSION=	0.02
CATEGORIES=	games converters
MASTER_SITES=	http://www.helsinki.fi/~sandvik/qwdlinux/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}-unix-source-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Converts QuakeWorld demos from QWD format to MVD format

WRKSRC=		${WRKDIR}/${PORTNAME}-unix
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for file in INSTALL README NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
