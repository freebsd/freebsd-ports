# Created by: markand
# $FreeBSD$

PORTNAME=	nsnake
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://releases.malikania.fr/nsnake/
EXTRACT_SUFX=	.tgz

MAINTAINER=	demelier.david@gmail.com
COMMENT=	Snake game written in C and ncurses

LICENSE=	MIT

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c -lcurses)

do-install:
	(cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin \
		&& ${INSTALL_MAN} ${PORTNAME}.6 ${STAGEDIR}${MANPREFIX}/man/man6)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
