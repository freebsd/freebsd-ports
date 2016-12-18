# Created by: ijliao
# $FreeBSD$

PORTNAME=	textmaze
PORTVERSION=	1.2
CATEGORIES=	games perl5
MASTER_SITES=	http://www.robobunny.com/projects/textmaze/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Generates mazes on a text terminal and lets you traverse them

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt

RUN_DEPENDS=	p5-Curses>=0:devel/p5-Curses

USES=		shebangfix perl5
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	textmaze
PLIST_FILES=	bin/textmaze

WRKSRC=		${WRKDIR}/TextMaze

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
