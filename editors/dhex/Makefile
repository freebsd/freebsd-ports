PORTNAME=	dhex
DISTVERSION=	0.69
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.dettus.net/dhex/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Ncurses-based hex-editor with diff mode
WWW=		https://www.dettus.net/dhex/

LICENSE=	GPLv2

USES=		ncurses

MANPAGE1=	dhex.1
MANPAGE5=	dhexrc.5 dhex_markers.5 dhex_searchlog.5

PLIST_FILES=	bin/dhex \
		share/man/man1/dhex.1.gz \
		share/man/man5/dhex_markers.5.gz \
		share/man/man5/dhex_searchlog.5.gz \
		share/man/man5/dhexrc.5.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MANPAGE1} ${STAGEDIR}${PREFIX}/share/man/man1
.for f in ${MANPAGE5}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/share/man/man5
.endfor

.include <bsd.port.mk>
