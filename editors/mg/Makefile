# New ports collection makefile for:	mg
# Date created:			14 May 2001
# Whom:				Dima Dorfman <dima@unixfreak.org>
#
# $FreeBSD$
#

PORTNAME=	mg
PORTVERSION=	20090107
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/ \
		http://homepage.boetes.org/software/mg/

MAINTAINER=	darcsis@gmail.com
COMMENT=	A small, fast Emacs-like editor

MAN1=	mg.1
MANCOMPRESSED=	no

HAS_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in README tutorial
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
