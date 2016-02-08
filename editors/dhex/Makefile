# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhex
PORTVERSION=	0.68
CATEGORIES=	editors
MASTER_SITES=	http://www.dettus.net/dhex/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ncurses-based hex-editor with diff mode

LICENSE=	GPLv2

USES=		ncurses
MANPAGE1=	dhex.1
MANPAGE5=	dhexrc.5 dhex_markers.5 dhex_searchlog.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MANPAGE1} ${STAGEDIR}${MANPREFIX}/man/man1
.for f in ${MANPAGE5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${MANPREFIX}/man/man5
.endfor

.include <bsd.port.mk>
