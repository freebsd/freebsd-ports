# New ports collection makefile for:	qtez
# Version required:			0.77a
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	qtez-0.85.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ibl.sk/qtez/download/

MAINTAINER=	will@FreeBSD.org

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_QT2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} --with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
USE_GMAKE=	yes
MAKE_ENV+=	PCFLAGS="${CXXFLAGS}"

.include <bsd.port.mk>
