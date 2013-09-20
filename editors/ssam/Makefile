# Created by: Serge Gagnon <serge.gagnon@b2b2c.ca>
# $FreeBSD$

PORTNAME=	ssam
PORTVERSION=	1.10
CATEGORIES=	editors plan9
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stream editor that uses the UTF routines with the sam(1) command set

BUILD_DEPENDS=	${LOCALBASE}/include/ure.h:${PORTSDIR}/misc/libutf

GNU_CONFIGURE=	YES
ALL_TARGET=	ssam

PLIST_FILES=	bin/ssam

MAN1=	ssam.1

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssam.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
