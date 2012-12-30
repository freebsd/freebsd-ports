# Ports collection makefile for:	ksudoku
# Date created:				30 September 2005
# Whom:					Bartosz Fabianowski <freebsd@chillt.de>
#
# $FreeBSD$
#

PORTNAME=	ksudoku
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	freebsd@chillt.de
COMMENT=	A Sudoku generator and solver for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_GL=		yes
USE_CMAKE=	yes

.include <bsd.port.mk>
