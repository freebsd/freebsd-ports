# ex:ts=8
# New ports collection makefile for:	textmaze
# Date created:			Sep 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	textmaze
PORTVERSION=	1.2
CATEGORIES=	games perl5
MASTER_SITES=	http://www.robobunny.com/projects/textmaze/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Generates mazes on a text terminal and lets you traverse them

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses

USE_PERL5=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/TextMaze
NO_BUILD=	yes
PLIST_FILES=	bin/textmaze

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
