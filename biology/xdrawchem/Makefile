# New ports collection makefile for:	xdrawchem
# Date created:				13 April 2000
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	xdrawchem
PORTVERSION=	0.83
CATEGORIES=	biology
MASTER_SITES=	http://www.prism.gatech.edu/~gte067k/xdrawchem/
DISTNAME=	xdc083
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" QTDIR="${X11BASE}"
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_QT2=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
