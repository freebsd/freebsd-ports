# ex:ts=8
# New ports collection makefile for:	textmaze
# Date created:			Sep 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	textmaze
PORTVERSION=	1.0
CATEGORIES=	games perl5
MASTER_SITES=	http://www.robobunny.com/projects/textmaze/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates mazes on a text terminal and lets you traverse them

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/TextMaze
NO_BUILD=	yes
PLIST_FILES=	bin/textmaze

post-patch:
	@${PERL} -pi -e "s,/usr/local/bin/perl,${PERL},g" ${WRKSRC}/textmaze

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/textmaze ${PREFIX}/bin

.include <bsd.port.mk>
