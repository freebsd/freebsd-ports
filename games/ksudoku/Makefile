# Ports collection makefile for:	ksudoku
# Date created:				30 September 2005
# Whom:					Bartosz Fabianowski <freebsd@chillt.de>
#
# $FreeBSD$
#

PORTNAME=	ksudoku
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@chillt.de
COMMENT=	A Sudoku generator and solver for KDE

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_GL=		yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

.include <bsd.port.mk>
