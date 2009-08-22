# ex:ts=8
# New ports collection makefile for:	cryptoslam
# Date created:			Nov 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cryptoslam
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses-based tool for creating and solving the cryptograms

PLIST_FILES=	bin/cryptoslam

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} cryptogram.cpp cryptoslam.cpp \
		-o ${PORTNAME} -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
