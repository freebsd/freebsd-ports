# New ports collection makefile for:	showkey
# Date created:				2003-10-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	showkey
PORTVERSION=	1.3
CATEGORIES=	converters
MASTER_SITES=	http://catb.org/~esr/showkey/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Prints its input, with escapes such as "<NUL>"

ALL_TARGET=	showkey
MAN1=		showkey.1
PLIST=		${WRKDIR}/pkg-plist

pre-install:
	${ECHO_CMD} bin/showkey > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/showkey ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/showkey.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
