# New ports collection makefile for:    picprog
# Date created:         31 August 1999
# Whom:                 Johan Kerckaert <kirk@bricsnet.com>
#
# $FreeBSD$
#

PORTNAME=	picprog
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=		picprog.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/picprog.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.gif ${DOCSDIR}
.endif

.include <bsd.port.mk>
