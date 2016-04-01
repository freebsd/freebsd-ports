# Created by: Serge Gagnon <serge.gagnon@b2b2c.ca>
# $FreeBSD$

PORTNAME=	ssam
PORTVERSION=	1.10
CATEGORIES=	editors plan9
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stream editor that uses the UTF routines with the sam(1) command set

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/include/ure.h:misc/libutf

GNU_CONFIGURE=	YES
ALL_TARGET=	ssam

PLIST_FILES=	bin/ssam man/man1/ssam.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssam ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssam.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
