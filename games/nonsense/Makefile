# New ports collection makefile for:	nonsense
# Date created:		15 December 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nonsense
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	http://i-want-a-website.com/about-linux/

MAINTAINER=	roam@FreeBSD.org

NO_BUILD=	defined

post-configure:
		${PERL} -pi -e "s,/usr/local,${PREFIX}," ${WRKSRC}/nonsense

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/nonsense ${PREFIX}/bin
		${MKDIR} ${PREFIX}/share/nonsense/data
		${MKDIR} ${PREFIX}/share/nonsense/template
		${INSTALL_DATA} ${WRKSRC}/*.data ${PREFIX}/share/nonsense/data
		${INSTALL_DATA} ${WRKSRC}/*.template ${PREFIX}/share/nonsense/template

.include <bsd.port.mk>
