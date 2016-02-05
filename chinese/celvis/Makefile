# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	celvis
PORTVERSION=	1.3
CATEGORIES=	chinese editors
MASTER_SITES=	http://ftp.ist.utl.pt/pub/ctan/language/chinese/chtex/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vi/ex clone that speaks Chinese

USES=		ncurses
CFLAGS+=	-Wno-error=return-type
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"

do-install:
	@# install target in celvis Makefile is not too good -- this is easier
	${INSTALL_PROGRAM} ${WRKSRC}/celvis ${WRKSRC}/virec ${STAGEDIR}${PREFIX}/bin
	${LN} -s celvis ${STAGEDIR}${PREFIX}/bin/cvi
	${INSTALL_MAN} ${FILESDIR}/celvis.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
