# New ports collection makefile for:	hex
# Date created:		Nov 5, 1996
# Whom:			IMAMURA Tomoaki (yu@pastel.club.or.jp)
#
# $FreeBSD$
#

PORTNAME=	hex
PORTVERSION=	2.04
CATEGORIES=	japanese
MASTER_SITES=	http://www.tsg.ne.jp/GANA/S/hex/
EXTRACT_SUFX=	.tgz
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A hexadecimal dump tool which handles Japanese

MANLANG=	ja
MAN1=		hex.1
PLIST_FILES=	bin/hex

do-build:
	cd ${WRKSRC}; ${CXX} ${CXXFLAGS} hex.cc -o hex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hex.man ${PREFIX}/man/ja/man1/hex.1

.include <bsd.port.mk>
