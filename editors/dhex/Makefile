# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dhex
PORTVERSION=	0.68
CATEGORIES=	editors
MASTER_SITES=	http://www.dettus.net/dhex/ \
		CRITICAL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ncurses-based hex-editor with diff mode

LICENSE=	GPLv2

MAN1=		dhex.1
MAN5=		dhexrc.5 dhex_markers.5 dhex_searchlog.5
PLIST_FILES=	bin/dhex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
.for f in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${MANPREFIX}/man/man5
.endfor

.include <bsd.port.mk>
