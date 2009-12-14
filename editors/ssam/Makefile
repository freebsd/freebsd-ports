# New ports collection makefile for:	ssam
# Date Created:				25 February 2006
# Whom:					Serge Gagnon <serge.gagnon@b2b2c.ca>
#
# $FreeBSD$
#

PORTNAME=	ssam
PORTVERSION=	1.9
CATEGORIES=	editors plan9
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stream editor that uses the UTF routines with the sam(1) command set

BUILD_DEPENDS=	${LOCALBASE}/include/ure.h:${PORTSDIR}/misc/libutf

GNU_CONFIGURE=	YES
ALL_TARGET=	ssam

PLIST_FILES=	bin/ssam

MAN1=	ssam.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssam ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssam.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
