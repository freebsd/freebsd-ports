# New ports collection makefile for:    picprog
# Date created:         31 August 1999
# Whom:                 Johan Kerckaert <kirk@bricsnet.com>
#
# $FreeBSD$
#

PORTNAME=	picprog
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Serial port pic16c84 programmer

USE_GETOPT_LONG=	yes

MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		picprog.1
DOCS=		README picprog.html *.gif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprog ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/picprog.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
