# ex:ts=8
# New ports collection makefile for:	lfhex
# Date created:			Jul 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfhex
PORTVERSION=	0.3.4
CATEGORIES=	editors
MASTER_SITES=	http://home.earthlink.net/~eyekode/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large file hex editor

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS=	--with-qt-moc=${MOC}

MAKE_ARGS=	EXEC_PREFIX="${PREFIX}/bin" \
		IFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		LFLAGS="${QTCFGLIBS} -lqt-mt ${PTHREAD_LIBS}"

.include <bsd.port.mk>
