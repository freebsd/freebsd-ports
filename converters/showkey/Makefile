# New ports collection makefile for:	showkey
# Date created:				2003-10-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	showkey
PORTVERSION=	1.4
CATEGORIES=	converters
MASTER_SITES=	http://catb.org/~esr/showkey/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prints its input, with escapes such as "<NUL>"

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC} ${CFLAGS}"
ALL_TARGET=	showkey

MAN1=		showkey.1
PLIST_FILES=	bin/showkey

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showkey ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/showkey.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
