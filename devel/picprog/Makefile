# New ports collection makefile for:    picprog
# Date created:         31 August 1999
# Whom:                 Johan Kerckaert <kirk@bricsnet.com>
#
# $FreeBSD$
#

PORTNAME=	picprog
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=		picprog.1

#post-patch:
#	$(CP) ${PATCHDIR}/getopt* ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/picprog
	${INSTALL_MAN} ${WRKSRC}/picprog.html ${PREFIX}/share/doc/picprog
	${INSTALL_MAN} ${WRKSRC}/*.gif ${PREFIX}/share/doc/picprog
.endif

.include <bsd.port.mk>
