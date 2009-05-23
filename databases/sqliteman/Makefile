# New ports collection makefile for:	sqliteman
# Date created:		19 May, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sqliteman
PORTVERSION=	1.2.1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	wenheping@gmail.com
COMMENT=	Admin's GUI tool for Sqlite3

LIB_DEPENDS=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_QT_VER=	4
USE_SQLITE=	yes
CMAKE_ENV+=	QMAKESPEC=${QMAKESPEC}
QT_COMPONENTS=	qmake_build gui moc_build rcc_build uic_build xml sql

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
