# New ports collection makefile for:    cmake
# Date created:         March 18 2002
# Whom:                 Kyle Martin <mkm@ieee.org>
#
# $FreeBSD$
#

PORTNAME=	cmake
PORTVERSION=	2.0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v${PORTVERSION:C/\.[[:digit:]]+$//}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform make

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR:S|^${PREFIX}||} --datadir=${DATADIR:S|^${PREFIX}||}

MAN1=		ccmake.1 cmake.1 ctest.1

.include <bsd.port.mk>
